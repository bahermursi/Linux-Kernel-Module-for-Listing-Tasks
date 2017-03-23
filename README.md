# Linux-Kernel-Module-for-Listing-Tasks

Each folder contains 2 files:
1)	makefile
2)	Linear_Iterations.c | Dfs_Itreations.c

How to run from the terminal

•	First open one of the two folders “Linear_list” or “Dfs_List” with: $ cd “folder path”  
•	Then after opening one of the two folders compile the files with: $ make	

•	Linear tasks iteration:
-	To list the iterations, use: $ sudo insmod Linear_Iterations.ko
-	To remove the iterations, use: $ sudo rmmod Linear_Iterations.ko

•	Similarly, for the Dfs tasks iteration:
-	To list the iterations, use: $ sudo insmod Dfs_Iterations.ko
-	To remove the iterations, use: $ sudo rmmod Dfs_Iterations.ko

•	For The messages:
-	To print the messages of the compiled file use: $ dmesg
-	To clear the messages from the terminal use: $ sudo dmesg - c									

