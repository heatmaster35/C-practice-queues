//###########################
//# Name: Leo Gomez         #
//# CruzID: legomez         #
//# Class: CMPS-12M         #
//# Date: Nov 24, 2014      #
//# filename: queue.h       #
//# Details: the queue (.h) #
//#    that allows functions#
//#    public in main.c     #
//###########################

#ifndef __QUEUE_H__
#define __QUEUE_H__

#include <stdbool.h>

/* External interface declarations */

struct queue;
typedef struct queue queue;
typedef char *queue_item_t;

/* Function declarations */

queue *queue_new(void);

void queue_free(queue*);

void queue_insert(queue*, queue_item_t);

queue_item_t queue_remove(queue*, queue_item_t*);

bool queue_isempty(queue*);

#endif
