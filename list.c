/*******************
 * Program: list.c
 * Author: Caden Johnsen
 * Date: 6/11/17
 * Description: Contains the functionality of the linked list
 * Input: None
 * Output: None
 *******************/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

void init(struct list *l) {
	/*******************
	 * Function: init
	 * Description: Initializes the list to null
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	l->head = NULL;
	l->tail = NULL;
}

int size(struct list l) {
	/*******************
	 * Function: size
	 * Description: Return number of nodes in list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	int i = 1;
	struct node *temp = l.head;

	if(empty(l) == 1) {
		return 0;
	}
	if(l.head == NULL) {
		return 1;
	}
	while(temp->next != NULL) {
		temp = temp->next;
		i++;
	}
	return i;
}

void print(struct list l) {
	/*******************
	 * Function: print
	 * Description: Print the values in list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	struct node *temp = l.head;
	while(temp != NULL) {
		printf("%d\n", temp->val);
		temp = temp->next;
	}
}

void push_front(struct list * l, int n) {
	/*******************
	 * Function: push_front
	 * Description: Push to front of list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	struct node *temp;
	if(empty((*l)) == 1) {
		temp = malloc(sizeof(struct node));
		temp->val = n;
		temp->next = l->head;
		l->head = temp;
		l->tail = l->head;
	}
	else {
		temp = malloc(sizeof(struct node));
		temp->val = n;
		temp->next = l->head;
		l->head = temp;
	}
}

void push_back(struct list *l, int n) {
	/*******************
	 * Function: push_back
	 * Description: Push to end of list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	struct node *temp;
	if(empty((*l)) == 1) {
		temp = malloc(sizeof(struct node));
		temp->val = n;
		temp->next = NULL;
		l->tail->next = temp;
		l->tail = temp;
		l->head = l->tail;
	}
	else {
		temp = malloc(sizeof(struct node));
		temp->val = n;
		temp->next = NULL;
		l->tail->next = temp;
		l->tail = temp;
	}

}

int front(struct list l) {
	/*******************
	 * Function: front
	 * Description: Return value at the front of the list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	return l.head->val;
}

int back(struct list l) {
	/*******************
	 * Function: back
	 * Description: Return value at the back of the list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	return l.tail->val;
}

int pop_back(struct list *l) {
	/*******************
	 * Function: pop_back
	 * Description: Remove node from back and return value
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	int val;
	struct node* temp = l->head;

	while(temp->next->next != NULL){
		temp = temp->next;
	}
	val = temp->next->val;
	temp->next = NULL;
	free(l->tail);
	l->tail = temp;

	return val;
}

int remove_front(struct list *l) {
	/*******************
	 * Function: remove_front
	 * Description: Remove node from front and return value
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	struct node* temp = l->head->next;
	int val = l->head->val;
	if(temp == NULL) {
		free(l->head);
		l->head = NULL;
		l->tail = NULL;
	}
	else {
		free(l->head);
		l->head = temp;
	}
	return val;
}

int empty(struct list l) {
	/*******************
	 * Function: empty
	 * Description: Returns true if list is empty
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	if(l.head == NULL && l.tail == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void delete(struct list *l) {
	/*******************
	 * Function: delete
	 * Description: Remove all nodes from list
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	int i;

	while(l->head != NULL) {
		free(l->head);
		l->head = l->head->next;
	}
	l->head = NULL;
	l->tail = NULL;
}
