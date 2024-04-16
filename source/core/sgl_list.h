/* source/core/sgl_list.h
 *
 * MIT License
 *
 * Copyright(c) 2023-present All contributors of SGL  
 *  
 * Email: 1477153217@qq.com
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef __SGL_LIST_H__
#define __SGL_LIST_H__

#ifdef __cplusplus
extern "C" {
#endif


#include <stdbool.h>

/*************************************************************************************
 * Function Name: container_of
 * Description: Get the address of the structure instance.
 *
 * Param:
 *   @ptr: address of the structure member.
 *   @struct_type: type of the structure.
 *   @member: member name of the ptr in structure.
 * Return:
 *   void
 ************************************************************************************/
#define   sgl_offsetof(struct_t, member)   ((size_t)&((struct_t*)0)->member)
#ifdef __cplusplus
#define container_of(ptr, type, member) ({ \
        typeof(((type *)0)->member)*__mptr = ptr; \
        (type *)((char *)__mptr - sgl_offsetof(type, member)); })
#else
#define container_of(ptr, type, member) ({ \
        typeof(((type *)0)->member)(*__mptr) = ((void *)ptr); \
        (type *)((char *)__mptr - sgl_offsetof(type, member)); })
#endif


#define __used  __attribute__((used))

/*************************************************************************************
 * @prev: previous node of the list.
 * @next: next node of the list.
 ************************************************************************************/
typedef struct sgl_list_node {
	struct sgl_list_node *prev;
	struct sgl_list_node *next;
}sgl_list_node_t;

#define SGL_LIST_HEAD(name) \
	sgl_list_node_t name = {.prev = &(name), .next = &(name)}

/*************************************************************************************
 * Function Name: sgl_list_for_each
 * Description: foreach the list.
 *
 * Param:
 *   @pos: the &struct list_head to use as a loop cursor.
 *   @list_head: the head for your list.
 * Return:
 *   void
 ************************************************************************************/
#define sgl_list_for_each(pos, list_head) \
	for (pos = (list_head)->next; pos != (list_head); pos = pos->next)

/*************************************************************************************
 * Function Name: sgl_list_next_entry
 * Description: Return the next entry of specific node.
 *
 * Param:
 *   @entry: specific entry.
 * Return:
 *   @entry_type: next entry of specific entry.
 ************************************************************************************/
#define sgl_list_next_entry(entry, entry_type, list_node_member) \
	container_of(entry->list_node_member.next, entry_type, list_node_member)

/*************************************************************************************
 * Function Name: sgl_list_prev_entry
 * Description: Return the previous entry of specific node.
 *
 * Param:
 *   @entry: specific entry.
 * Return:
 *   @entry_type: previous entry of specific entry.
 ************************************************************************************/
#define sgl_list_prev_entry(entry, entry_type, list_node_member) \
	container_of(entry->list_node_member.prev, entry_type, list_node_member)

/*************************************************************************************
 * Function Name: sgl_list_for_each_entry
 * Description: foreach the list inserted in a structure.
 *
 * Param:
 *   @pos: the &struct list_head to use as a loop cursor.
 *   @list_head: the head for your list.
 *   @entry_type: type of the struct.
 *   @list_node_member: member name of the list_node in structure.
 * Return:
 *   void
 ************************************************************************************/
#define sgl_list_for_each_entry(pos, list_head, entry_type, list_node_member) \
	for (pos = container_of((list_head)->next, entry_type, list_node_member); \
	     &pos->list_node_member != (list_head); \
	     pos = container_of(pos->list_node_member.next, entry_type, list_node_member))

/*************************************************************************************
 * Function Name: sgl_list_init
 * Description: inititialize a list.
 *
 * Param:
 *   @node: inserted node.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_init(sgl_list_node_t *node) 
{
	node->next = node;
	node->prev = node;
}

/*************************************************************************************
 * Function Name: sgl_list_add_node_at_tail
 * Description: Add a node to the list tail.
 *
 * Param:
 *   @head: head node of the list.
 *   @node: inserted node.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_add_node_at_tail(sgl_list_node_t *head, sgl_list_node_t *node)
{
	sgl_list_node_t *tail = head->prev;

	node->prev = tail;
	node->next = head;
	tail->next = node;
	head->prev = node;
}

/*************************************************************************************
 * Function Name: sgl_list_add_node_at_front
 * Description: Add a node to the list front.
 *
 * Param:
 *   @head: head node of the list.
 *   @node: inserted node.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_add_node_at_front(sgl_list_node_t *head, sgl_list_node_t *node)
{
	sgl_list_node_t *front = head->next;

	node->prev = head;
	node->next = front;
	front->prev = node;
	head->next = node;
}

/*************************************************************************************
 * Function Name: sgl_list_del_tail_node
 * Description: Delete a tail node from the list.
 *
 * Param:
 *   @head: head node of the list.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_del_tail_node(sgl_list_node_t *head)
{
	sgl_list_node_t *tail_prev = head->prev->prev;

	tail_prev->next = head;
	head->prev = tail_prev;
}

/*************************************************************************************
 * Function Name: sgl_list_del_front_node
 * Description:  Delete a front node from the list.
 *
 * Param:
 *   @head: head node of the list.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_del_front_node(sgl_list_node_t *head)
{
	sgl_list_node_t *front_next = head->next->next;

	front_next->prev = head;
	head->next = front_next;
}

/*************************************************************************************
 * Function Name: sgl_list_del_node
 * Description:  Delete a node from the list.
 *
 * Param:
 *   @node: the node of the list.
 * Return:
 *   void
 ************************************************************************************/
static void __used sgl_list_del_node(sgl_list_node_t *node)
{
	node->prev->next = node->next;
	node->next->prev = node->prev;
}

/*************************************************************************************
 * Function Name: sgl_list_is_empty
 * Description: Determine whether the list is empty.
 *
 * Param:
 *   @head: head node of the list.
 * Return:
 *   @bool: is empty.
 ************************************************************************************/
static bool __used sgl_list_is_empty(sgl_list_node_t *head)
{
	return head->next == head;
}

/*************************************************************************************
 * Function Name: sgl_list_next_node
 * Description: Return the next node of specific node.
 *
 * Param:
 *   @node: specific node.
 * Return:
 *   @list_node*: next node of specific node.
 ************************************************************************************/
static sgl_list_node_t* __used sgl_list_next_node(sgl_list_node_t *node)
{
	return node->next;
}

/*************************************************************************************
 * Function Name: sgl_list_prev_node
 * Description: Return the previous node of specific node.
 *
 * Param:
 *   @node: specific node.
 * Return:
 *   @list_node*: previous node of specific node.
 ************************************************************************************/
static sgl_list_node_t* __used sgl_list_prev_node(sgl_list_node_t *node)
{
	return node->prev;
}


#ifdef __cplusplus
}
#endif

#endif /* __SGL_LIST_H__ */
