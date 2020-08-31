/*******************
 * Program: test_list.c
 * Author: Caden Johnsen
 * Date: 6/11/17
 * Description: A program creating a linked list and messing with it
 * Input: None
 * Output: None
 *******************/
#include "list.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	/*******************
	 * Function: main
	 * Description: Initializes values and calls functions
	 * Parameters: None
	 * Input: None
	 * Output: None
	 *******************/
	struct list l;
	char c;
	char ch[20];
	int i;
	int j;

	system("clear");
	init(&l);
	printf("Values:\n");
	push_front(&l, 3);
	l.tail = l.head;
	push_front(&l, 2);
	push_front(&l, 1);
	push_front(&l, 0);
	push_back(&l, 4);
	push_back(&l, 5);
	push_back(&l, 6);
	print(l);
	printf("Size: %d\n", size(l));
	printf("Front: %d\n", front(l));
	printf("Back: %d\n", back(l));
	printf("Last Value Removed: %d\n", pop_back(&l));
	printf("First Value Removed: %d\n", remove_front(&l));
	printf("Remaining Values:\n");
	print(l);
	printf("Before delete list is ");
	if(empty(l) == 1) {
		printf("empty\n");
	}
	else {
		printf("not empty\n");
	}
	delete(&l);
	printf("After delete list is ");
	if(empty(l) == 1) {
		printf("empty\n");
	}
	else {
		printf("not empty\n");
	}

	printf("Press Enter to test Mini Compiler.\n");
	scanf("%c", &c);
	system("clear");
	init(&l);
	for(j = 0; j < 20; j++) {
		ch[j] = 'i';
	}

	printf("Mini Compiler:\nEnter in a set of [], (), or {}.\n");
	scanf("%s", ch);

	for(i = 0; i < strlen(ch); i++) {
		if(ch[i] == '(') {
			push_front(&l, 1);
		}
		else if(ch[i] == '{') {
			push_front(&l, 2);
		}
		else if(ch[i] == '[') {
			push_front(&l, 3);
		}
		else if(ch[i] == ')') {
			if(l.head != NULL && l.head->val == 1) {
				remove_front(&l);
			}
			else {
				break;
			}
		}
		else if(ch[i] == '}') {
			if(l.head != NULL && l.head->val == 2) {
				remove_front(&l);
			}
			else {
				break;
			}
		}
		else if(ch[i] == ']') {
			if(l.head != NULL && l.head->val == 3) {
				remove_front(&l);
			}
			else {
				break;
			}
		}
		else {
			printf("Input incorrect.\n");
			delete(&l);
			return 0;
		}
	}

	if(size(l) == 0 && i == strlen(ch)) {
		printf("Everything works. Input correct.\n");
	}
	else {
		printf("Input incorrect.\n");
	}
	delete(&l);

	return 0;
}

