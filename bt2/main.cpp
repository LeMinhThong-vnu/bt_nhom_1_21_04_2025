#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
};

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

void printReverse(Node* head){
    if (head == nullptr) return;
    printReverse(head->next);
    cout << head->value << ' ';
}

int main() {
    int n;
    cin >> n;
    Node* head = inputList(n);
    printReverse(head);
}

