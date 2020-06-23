#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

#define ARRAY_SIZE = 1024 * 1000
#define BUF_SIZE = 192


char buf[BUF_SIZE] = { 0 };
char* array = NULL;

int init_module(void) {
    char* array = kvmalloc_array(ARRAY_SIZE, 192, GFP_KERNEL);
    for(int i = 0; i < ARRAY_SIZE, i++) {
        printk("Allocating buffer %d with size 192\n", i);
        memcpy(array[i], buf, BUF_SIZE);
    }
}


int cleanup_module(void) {
    if(array != NULL) {
        kvfree(array);
    }
}

MODULE_LICENSE("GPL");
