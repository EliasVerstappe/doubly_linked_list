#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


struct node_t {
    uint32_t value;
    struct node_t* next;
    struct node_t* prev;
};

struct node_t* create_head_node_ptr(uint32_t value);
bool insert(uint32_t value, struct node_t* head_node_ptr);
bool delete_index(uint32_t index, struct node_t* node_ptr);
void print_list(struct node_t* node_ptr, bool front_to_back);
struct node_t* find_head_node_ptr(struct node_t* node_ptr);
struct node_t* find_tail_node_ptr(struct node_t* node_ptr);
bool insert_index(uint32_t inserted_value, uint32_t index, struct node_t* node_ptr);



int main() {

    struct node_t* head_node_ptr = create_head_node_ptr(0);

    if (head_node_ptr != NULL) {

        printf("\nInserting values...\n");
        uint8_t i = 1;
        for (i = 1; i < 10; i++) {
            if(insert(i, head_node_ptr) == false) {
                printf("\t! INSERTING NODE FAILED !\n");
                break;
            }
        }
        printf("\t... done!\n");

        

        printf("\nPrinting list front to back:\n");
        print_list(head_node_ptr, true);
        printf("\nPrinting list back to front:\n");
        print_list(head_node_ptr, false);


        printf("\nFetching node with index 3 ...\n");
        struct node_t* node_3_ptr = head_node_ptr->next->next->next;
        printf("\t... Value of node: %d\n", node_3_ptr->value);

        printf("\nPrinting list front to back, giving third node as argument:\n");
        print_list(node_3_ptr, true);
        

        printf("\nDeleting at index 5 ...\n");
        if(delete_index(5, head_node_ptr) == false) {
            printf("\t! DELETE NODE FAILED !\n");
        } else {
            printf("\t... Node deleted\n");
        }
        printf("\nPrinting list:\n");
        print_list(head_node_ptr, true);
        printf("\n\t& backwards:\n");
        print_list(head_node_ptr, false);


        printf("\nInserting new node with value 22 at index 3 ...\n");
        if(insert_index(22, 3, head_node_ptr) == false) {
            printf("\t! INSERTING NODE FAILED !\n");
        }
        printf("\nPrinting list:\n");
        print_list(head_node_ptr, true);
        printf("\n\t& backwards:\n");
        print_list(head_node_ptr, false);


    }
    
}

struct node_t* create_head_node_ptr(uint32_t value) {
    struct node_t* new_node_ptr = malloc(sizeof(struct node_t));

    if (new_node_ptr != NULL)
    {
        new_node_ptr->value = value;
        new_node_ptr->next = NULL;
        new_node_ptr->prev = NULL;

        return new_node_ptr;
    } else {
        return NULL;
    }
}

/**
 *  Adds a new node to the end of the list, new node hols 'value'
 * 
 *  [value]     Value that is stored in the new node
 *  [node_ptr]  Pointer to a node in the list
 *  Returns 1 on success and 0 on failure
 */
bool insert(uint32_t value, struct node_t* head_node_ptr) {

    struct node_t* new_node_ptr = malloc(sizeof(struct node_t));

    if (new_node_ptr != NULL)
    {
        // On node creation success, insert new node at the end

        // Fill in value field
        new_node_ptr->value = value;
        new_node_ptr->next = NULL;
        new_node_ptr->prev = NULL;

        // Insert node, find last node...
        struct node_t* loop_node_ptr = head_node_ptr;
        while (loop_node_ptr->next != NULL) {
            loop_node_ptr = loop_node_ptr->next;
        }
        // Insert node, insert new node at the end...
        // value of loop_node_ptr here is a pointer to the last node in the list, before inserting the new node obvs.  
        loop_node_ptr->next = new_node_ptr;
        // Doubly linked so add pointer to previous element
        new_node_ptr->prev = loop_node_ptr;
        

        return true;
    } else {
        return false;
    }
}

/**
 *  Insert new node @ index
 * 
 */
bool insert_index(uint32_t inserted_value, uint32_t index, struct node_t* node_ptr) {

    struct node_t* new_node_ptr = malloc(sizeof(struct node_t));

    if (new_node_ptr != NULL) {

        struct node_t* loop_node_ptr = find_head_node_ptr(node_ptr);
        struct node_t* prev_node_ptr = NULL;

        uint32_t iterator = 0;
        while (loop_node_ptr->next != NULL) {
      
            if (iterator == index) {
                
                new_node_ptr->value = inserted_value;
                new_node_ptr->next = loop_node_ptr;
                new_node_ptr->prev = prev_node_ptr;

                prev_node_ptr->next = new_node_ptr;
                loop_node_ptr->prev = new_node_ptr;

                return true;
            }
            
            prev_node_ptr = loop_node_ptr;
            loop_node_ptr = loop_node_ptr->next;
            iterator++;
        }

        return false;
    } else {
        return false;
    }
}

/**
 *  Deletes the the N-th node, where N is the given index
 * 
 *  Returns 1 on success and 0 on failure
 */
bool delete_index(uint32_t index, struct node_t* node_ptr) {

    struct node_t* loop_node_ptr = find_head_node_ptr(node_ptr);
    struct node_t* prev_node_ptr = NULL;
    uint32_t iterator = 0;
    while (loop_node_ptr->next != NULL) {
        if (iterator == index) {
            prev_node_ptr->next = loop_node_ptr->next;
            loop_node_ptr->next->prev = prev_node_ptr;

            free(loop_node_ptr);

            return true;
        }      
        prev_node_ptr = loop_node_ptr;
        loop_node_ptr = loop_node_ptr->next;
        iterator++;
    }
    return false;
}

/**
 *  Prints the linked list
 * 
 * @param node_ptr any node in the list
 * @param front_to_back 1 to print from front to back, 0 to print from back to front
 */
void print_list(struct node_t* node_ptr, bool front_to_back) {

    // Determine if pointer is first node, last node or any node in between
    if (node_ptr->prev == NULL && node_ptr->next == NULL) {
        // Only one node in the list
        printf("Value: [ %3d ]\n", node_ptr->value);
        return;

    } 

    struct node_t* head_node_ptr = find_head_node_ptr(node_ptr);
    struct node_t* tail_node_ptr = find_tail_node_ptr(node_ptr);    
    
    struct node_t* loop_ptr = NULL;
    if (front_to_back) {
        // If front to back, loop_ptr should be head_node_ptr
        loop_ptr = head_node_ptr;
    } else {
        // If back to front, loop_ptr should be tail_node_ptr
        loop_ptr = tail_node_ptr;
    }
    
    while (loop_ptr != NULL) {
        printf("Value: [ %3d ]\n", loop_ptr->value);

        if (front_to_back) {
            // Print list from front to back
            loop_ptr = loop_ptr->next;
        } else {
            // Print list from back to front
            loop_ptr = loop_ptr->prev;
        }        
    }
    
}

struct node_t* find_head_node_ptr(struct node_t* node_ptr) {
    if (node_ptr->prev == NULL) {
        // node_ptr is head of list
        return node_ptr;
    } else {
        // node_ptr->prev != NULL meaning that other nodes are in front of this node
        // Find head node

        struct node_t* loop_ptr = node_ptr;
        while (loop_ptr->prev != NULL)  loop_ptr = loop_ptr->prev;

        // loop_ptr now contains head node ptr
        return loop_ptr;
    }
}

struct node_t* find_tail_node_ptr(struct node_t* node_ptr) {
    if (node_ptr->next == NULL) {
        // node_ptr is tail of list
        return node_ptr;
    } else {
        // node_ptr->next != NULL meaning that other nodes are in front of this node
        // Find tail node
        
        struct node_t* loop_ptr = node_ptr;
        while (loop_ptr->next != NULL)  loop_ptr = loop_ptr->next;

        // loop_ptr now contains head node ptr
        return loop_ptr;
    }
}