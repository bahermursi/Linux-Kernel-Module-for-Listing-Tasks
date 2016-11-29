//Baher Moursy
//900131407
#include <linux/init.h>
#include <linux/sched.h>
#include <linux/kernel.h>
#include <linux/module.h>


/* This function is called when the module is loaded. */
int simple_init(void) {
	
	struct task_struct *task;
	
	printk(KERN_INFO ":Listing Modules: \n");
	
	for_each_process(task) {
		/* on each iteration task points to the next task */
		
		/*task->comm Macro to get the task name */
		/*task->state Macro to get the state of the process */
		/*task->pid Macro to get the process ID */
		printk(KERN_INFO "State Name: %s - State: %ld - Proccess ID: %d\n",task->comm, task->state, task->pid);
	}
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Module\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Kernel Module for Listing Tasks (Linear)");
MODULE_AUTHOR("Baher Moursy, 900131407");
