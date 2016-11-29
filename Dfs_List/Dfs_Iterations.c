//Baher Moursy
//900131407
#include <linux/sched.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* This function is called when the module is loaded. */
void dfs(struct task_struct *init_task) {

	struct task_struct *next; /*Pointer used to get the next child in the list to be traversed*/
	struct list_head *list; /*A pointer to the head of the list to be traversed*/
	
	/*init_task->comm Macro to get the task name */
	/*init_task->state Macro to get the state of the process */
	/*init_task->pid Macro to get the process ID */
	printk(KERN_INFO "State Name: %s - State: %ld - Proccess ID: %d\n",init_task->comm, init_task->state, init_task->pid);
	
	/*Instruction to iterate over the children of init_task*/
	list_for_each(list, &init_task->children) {
		next = list_entry(list, struct task_struct, sibling); /* next points to the next child in the list */
		dfs(next); /*dfs on the next child in the list*/
	}
	
}

int simple_init(void) {
	printk(KERN_INFO "Listing Modules:\n");
	dfs(&init_task); /*dfs on initial task*/
	return 0;
}

/* This function is called when the module is removed. */
void simple_exit(void) {
	printk(KERN_INFO "Removing Modules:\n");
}

/* Macros for registering module entry and exit points. */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Linux Kernel Module for Listing Tasks (Dfs)");
MODULE_AUTHOR("Baher Moursy, 900131407");