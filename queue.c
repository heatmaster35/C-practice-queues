//##############################
//# Name: Leo Gomez            #
//# CruzID: legomez            #
//# Class: CMPS-12M            #
//# Date: Nov 24, 2014         #
//# filename: queue.c          #
//# Details: the queue function#
//#   that keeps track of each #
//#   line                     #
//##############################

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"

#define STUBPRINTF(...) fprintf(stderr, __VA_ARGS__);

/* Internal implementation definitions */
struct queue_node 
{
  queue_item_t item;
  struct queue_node *link;
};

typedef struct queue_node queue_node;

struct queue 
{
  queue_node *front;
  queue_node *rear;
};

/* Functions */

queue *queue_new(void) 
{
  //STUBPRINTF("return NULL\n");
  queue *queueh = malloc(sizeof (struct queue));
  queueh->front = queueh->rear = NULL;
  return queueh;
}

void queue_free(queue *this) 
{
  assert(queue_isempty(this));
  free(this);
}

void queue_insert(queue *this, queue_item_t item) 
{
  //STUBPRINTF("item = \"%s\"\n", item);
  queue_node *temp = malloc(sizeof(struct queue_node));
  temp->item = item;
  if(queue_isempty(this))
    {
      this->rear = this->front = temp;
    }
  else
    {
      this->rear->link = temp;
      this->rear = this->rear->link;
      this->rear->link = NULL;
    }
}

queue_item_t queue_remove(queue *this, queue_item_t *leftover) 
{
  assert(!queue_isempty(this));
  //STUBPRINTF("return NULL\n");
  queue_node *i = this->front;
  queue_item_t result = i->item;
  *leftover = result;
  this->front = this->front->link;
  free(i);
  return result;
}

bool queue_isempty(queue *this) {
  return this->front == NULL;
}
