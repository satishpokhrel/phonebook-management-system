#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char name[30];
    char number[15];
    struct Node* next;
};

void createContact(struct Node** head, char name[],char number[]){
    struct Node *ptr;
    ptr=(struct Node*)malloc(sizeof(struct Node));
    strcpy(ptr->name, name);
    strcpy(ptr->number, number);
    ptr->next=*head;
    *head=ptr;
    printf("\nContact Added\n");
}

void displayContacts(struct Node* head){
    if(head==NULL){
        printf("\nPhonebook is empty.\n");
        return;
    }
    struct Node* current = head;
    printf("\nPhonebook Contact:\n\n");
    while(current!=NULL){
        printf("Name: %s, Phone:%s",current->name,current->number);
        current=current->next;
        printf("\n");
    }
}

//Function to search contact by name
void searchContact(struct Node* head,char name[]){
    struct Node* current = head;
    while(current!=NULL){
        if(strcmp(current->name, name)==0){
            printf("\nContact Found:\n");
            printf("Name: %s, Phone: %s\n", current->name, current->number);
            return;
        }
        current=current->next;
    }
    printf("\nContact not found.\n");
}

//function to delete existing contact frome phonebook
void deleteContact(struct Node** head,char name[]){
    struct Node* current = *head;
    struct Node* prev=NULL;

    while(current!=NULL){
        if(strcmp(current->name,name)==0){
            if(prev==NULL){
                *head=current->next;
            } else{
                prev->next=current->next;
            }
            free(current);
            printf("\nContact deleted successfully.\n");
            return;
        }
        prev=current;
        current=current->next;
    }
    printf("\nContact not found.\n");
}
//function to clear the phonebook
void clear(struct Node** head){
    struct Node* current=*head;
    while(current!=NULL){
        struct Node* temp=current;
        current=current->next;
        free(temp);
    }
    *head=NULL;
    printf("\nPhonebook cleared successfully.\n");
}
void hold(){
    char ch;
    while(ch!='q'){
        while(getchar()!='\n')
            continue;
        printf("\nEnter a character (q to quit to menu): ");
        ch = getchar();
    }
}

// Function to merge two sorted linked lists
struct Node* mergeSortedLists(struct Node* list1, struct Node* list2) {
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;

    struct Node* mergedList = NULL;

    if (strcmp(list1->name, list2->name) <= 0) {
        mergedList = list1;
        mergedList->next = mergeSortedLists(list1->next, list2);
    } else {
        mergedList = list2;
        mergedList->next = mergeSortedLists(list1, list2->next);
    }

    return mergedList;
}

// Function to split the linked list into two halves
void splitLinkedList(struct Node* source, struct Node** frontRef, struct Node** backRef) {
    struct Node* slow = source;
    struct Node* fast = source->next;

    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Merge Sort function for sorting the linked list alphabetically
void mergeSort(struct Node** head) {
    struct Node* current = *head;
    struct Node* a;
    struct Node* b;

    // Base case: If the list is empty or has only one element, it is already sorted.
    if (current == NULL || current->next == NULL) {
        return;
    }

    // Split the list into two halves.
    splitLinkedList(current, &a, &b);

    // Recursively sort the two halves.
    mergeSort(&a);
    mergeSort(&b);

    // Merge the sorted halves.
    *head = mergeSortedLists(a, b);
}

// Function to sort contacts alphabetically in the phonebook
void sortContacts(struct Node** head) {
    if (*head == NULL) {
        printf("Phonebook is empty.\n");
        return;
    }

    // Perform Merge Sort to sort the linked list.
    mergeSort(head);
    printf("Phonebook sorted alphabetically.\n");
}

int main(){
    struct Node* phonebook=NULL;
    char name[50], phone[15];
    int choice,garbage;

    //banner
    printf("\n\n");
    printf("\t\t██████╗░██╗░░██╗░█████╗░███╗░░██╗███████╗██████╗░░█████╗░░█████╗░██╗░░██╗\n");
    printf("\t\t██╔══██╗██║░░██║██╔══██╗████╗░██║██╔════╝██╔══██╗██╔══██╗██╔══██╗██║░██╔╝\n");
    printf("\t\t██████╔╝███████║██║░░██║██╔██╗██║█████╗░░██████╦╝██║░░██║██║░░██║█████═╝░\n");
    printf("\t\t██╔═══╝░██╔══██║██║░░██║██║╚████║██╔══╝░░██╔══██╗██║░░██║██║░░██║██╔═██╗░                    ___________________________________ \n");
    printf("\t\t██║░░░░░██║░░██║╚█████╔╝██║░╚███║███████╗██████╦╝╚█████╔╝╚█████╔╝██║░╚██╗                   |                                   |\n");
    printf("\t\t╚═╝░░░░░╚═╝░░╚═╝░╚════╝░╚═╝░░╚══╝╚══════╝╚═════╝░░╚════╝░░╚════╝░╚═╝░░╚═╝                   |       Project submitted by:       |\n");
    printf("\t\t                                                                                            |                                   |\n");
    printf("\t\t███╗░░░███╗░█████╗░███╗░░██╗░█████╗░░██████╗░███████╗███╗░░░███╗███████╗███╗░░██╗████████╗  |-----------------------------------|\n");
    printf("\t\t████╗░████║██╔══██╗████╗░██║██╔══██╗██╔════╝░██╔════╝████╗░████║██╔════╝████╗░██║╚══██╔══╝  |                                   |\n");
    printf("\t\t██╔████╔██║███████║██╔██╗██║███████║██║░░██╗░█████╗░░██╔████╔██║█████╗░░██╔██╗██║░░░██║░░░  |     Ankita Khadka(Roll no: 3)     |\n");
    printf("\t\t██║╚██╔╝██║██╔══██║██║╚████║██╔══██║██║░░╚██╗██╔══╝░░██║╚██╔╝██║██╔══╝░░██║╚████║░░░██║░░░  |     Khusi Subedi(Roll no: 10)     |\n");
    printf("\t\t██║░╚═╝░██║██║░░██║██║░╚███║██║░░██║╚██████╔╝███████╗██║░╚═╝░██║███████╗██║░╚███║░░░██║░░░  |    Prabin Ghimire(Roll no: 16)    |\n");
    printf("\t\t╚═╝░░░░░╚═╝╚═╝░░╚═╝╚═╝░░╚══╝╚═╝░░╚═╝░╚═════╝░╚══════╝╚═╝░░░░░╚═╝╚══════╝╚═╝░░╚══╝░░░╚═╝░░░  |     Riya Mishra(Roll no: 22)      |\n");
    printf("\t\t                                                                                            |   Satish Pokharel(Roll no: 28)    |\n");
    printf("\t\t░██████╗██╗░░░██╗░██████╗████████╗███████╗███╗░░░███╗                                       |                                   |\n");
    printf("\t\t██╔════╝╚██╗░██╔╝██╔════╝╚══██╔══╝██╔════╝████╗░████║                                        ----------------------------------- \n");
    printf("\t\t╚█████╗░░╚████╔╝░╚█████╗░░░░██║░░░█████╗░░██╔████╔██║\n");
    printf("\t\t░╚═══██╗░░╚██╔╝░░░╚═══██╗░░░██║░░░██╔══╝░░██║╚██╔╝██║\n");
    printf("\t\t██████╔╝░░░██║░░░██████╔╝░░░██║░░░███████╗██║░╚═╝░██║\n");
    printf("\t\t╚═════╝░░░░╚═╝░░░╚═════╝░░░░╚═╝░░░╚══════╝╚═╝░░░░░╚═╝\n");

    printf("\n\n");

    //program starts
    do{
    printf("\n\n\t\t");
    printf("1).Add new Contact.\n");
    printf("\t\t2)View all contacts.\n");
    printf("\t\t3)Search a contact.\n");
    printf("\t\t4)Delete an existing contact.\n");
    printf("\t\t5)Clear phonebook\n");
    printf("\t\t6)Exit\n\n");
    printf("\nEnter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:
            printf("\nAdd new Contact.\n");
            printf("\nEnter name: ");
            scanf(" %[^\n]",name);
            printf("Enter phone number: ");
            scanf(" %[^\n]",phone);
            createContact(&phonebook, name, phone);
            sortContacts(&phonebook);
            hold();
            break;
        case 2:
            displayContacts(phonebook);
            hold();
            break;
        case 3:
            printf("\nEnter Name to search: ");
            scanf(" %[^\n]",name);
            searchContact(phonebook,name);
            hold();
            break;
        case 4:
            printf("\nEnter name to delete: ");
            scanf(" %[^\n]",name);
            deleteContact(&phonebook, name);
            hold();
            break;
        case 5:
            clear(&phonebook);
            hold();
            break;
        case 6:
            printf("\n\nExiting.... \n");
            break;
        default:
            (printf("\n\nInvalid choice.Try again\n"));
      }
    }
while(choice!=6);

return 0;
}
