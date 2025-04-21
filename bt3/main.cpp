#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

void printList(Node* &head) {
    Node* curr = head;
    while (curr != NULL) {
        printf("%d ", curr->value);
        curr = curr->next;
    }
    cout << endl;
}

void removeDuplicates(Node* &head) {
    Node* curr = head;
    if (curr == NULL) return;
    if (curr->next == NULL) return;
    Node* next = head->next;
    if (next == NULL) return;
    while (next != NULL) {
        // printf("curr: %d\nnext: %d\n", curr->value, next->value);
        if (curr->value == next->value) {
            if (next->next == NULL) { // Tail
                // printf("a\n");
                curr->next = NULL;
                delete next;
                return;
            }
            else {
                // printf("b\n");
                curr->next = next->next;
                delete next;
                next = curr->next;
            }
        }
        else {
            // printf("c\n");
            curr = next;
            next = next->next;
        }
        // // printf("curr: %d\nnext: %d\n", curr->value, next->value);
        // printList(head);
        // cout << endl;
    }
}

Node* inputList(int n) {
    if (n <= 0) return NULL;
    Node* prev = NULL;
    Node* curr = new Node();
    Node* head = curr;
    for (int i = 0; i < n; i++) {
        curr->prev = prev;
        cin >> curr->value;
        if (i == n - 1) {
            curr->next = NULL;
        }
        else {
            Node* node = new Node();
            curr->next = node;
        }
        prev = curr;
        curr = curr->next;
    }
    return head;
}

int main() {
    int n;
    cin >> n;
    Node* head = inputList(n);
    removeDuplicates(head);
    printList(head);
}
