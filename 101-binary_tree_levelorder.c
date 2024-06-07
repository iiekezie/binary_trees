#include "queue.h"
#include <stdlib.h>

/**
 * create_queue_node - Creates a new queue node
 * @node: A pointer to a binary tree node
 *
 * Return: A pointer to the newly created queue node
 */
QueueNode *create_queue_node(const binary_tree_t *node)
{
    QueueNode *new_node = malloc(sizeof(QueueNode));
    if (new_node == NULL)
        return NULL;
    new_node->node = node;
    new_node->next = NULL;
    return new_node;
}

/**
 * enqueue - Adds a node to the rear of the queue
 * @queue: A double pointer to the queue
 * @node: A pointer to the binary tree node to be enqueued
 */
void enqueue(Queue **queue, const binary_tree_t *node)
{
    QueueNode *new_node = create_queue_node(node);
    if (new_node == NULL)
        return;
    if (*queue == NULL)
    {
        *queue = malloc(sizeof(Queue));
        if (*queue == NULL)
        {
            free(new_node);
            return;
        }
        (*queue)->front = (*queue)->rear = new_node;
    }
    else
    {
        (*queue)->rear->next = new_node;
        (*queue)->rear = new_node;
    }
}

/**
 * dequeue - Removes a node from the front of the queue
 * @queue: A double pointer to the queue
 *
 * Return: A pointer to the binary tree node dequeued from the queue
 */
const binary_tree_t *dequeue(Queue **queue)
{
    if (*queue == NULL || (*queue)->front == NULL)
        return NULL;
    QueueNode *temp = (*queue)->front;
    const binary_tree_t *node = temp->node;
    (*queue)->front = (*queue)->front->next;
    free(temp);
    if ((*queue)->front == NULL)
        (*queue)->rear = NULL;
    return node;
}