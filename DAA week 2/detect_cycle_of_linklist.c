#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int detectCycle(struct Node* head) {
    struct Node *slow = head, *fast = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            return 1;  // Cycle detected
        }
    }

    return 0;  // No cycle
}

int main() {
    int n, pos;
    struct Node *head = NULL, *tail = NULL, *cycleTarget = NULL;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int value;
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &value);

        struct Node* newNode = createNode(value);

        if (head == NULL) {
            head = newNode;
        } else {
            tail->next = newNode;
        }

        tail = newNode;

        if (i == 0) cycleTarget = head;  // default cycle target
    }

    printf("Enter position to create cycle (0 for no cycle, 1 to %d): ", n);
    scanf("%d", &pos);

    if (pos > 0 && pos <= n) {
        struct Node* temp = head;
        for (int i = 1; i < pos; i++) {
            temp = temp->next;
        }
        tail->next = temp;
    }

    if (detectCycle(head)) {
        printf("Cycle detected in the linked list.\n");
    } else {
        printf("No cycle in the linked list.\n");
    }

    return 0;
}