// Given the head of a linked list, determine whether the list contains a loop. If a loop 
// is present, return the number of nodes in the loop, otherwise return 0.

// Note: Internally, pos(1 based index) is used to denote the position of the node that tail's next
//  pointer is connected to. If pos = 0, it means the last node points to null, indicating there is 
//  no loop. Note that pos is not passed as a parameter.

// Examples:

// Input: pos = 2,   
// Output: 4
// Explanation: There exists a loop in the linked list and the length of the loop is 4.

// Input: pos = 3,   
// Output: 3
// Explanation: The loop is from 19 to 10. So length of loop is 19 → 33 → 10 = 3.

// Input: pos = 0,    
// Output: 0
// Explanation: There is no loop.

#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list node
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


class Solution {
  public:
    int lengthOfLoop(Node *head) {
        // code here
        Node *slow = head;
        Node *fast = head;
        
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast){
                break; // cycle means here 
            }
        }
        if(fast == NULL || fast->next == NULL){
            return 0;
        }
        
        Node *start = slow;
        Node *temp = head;
        
        while(start != temp){
            start = start->next;
            temp = temp->next;
        }
        
        int len = 1;
        
        Node *curr = temp->next;
        
        while(curr != temp){
            len = len+1;
            curr = curr->next;
        }
        return len;
    }
};

    int main() {
        // Example usage:
        Node* head = new Node(1);
        head->next = new Node(2);
        head->next->next = new Node(3);
        head->next->next->next = new Node(4);
        head->next->next->next->next = head->next; // Creating a loop for testing

        Solution sol;
        int loopLength = sol.lengthOfLoop(head);
        cout << "Length of the loop is: " << loopLength << endl; // Output should be 3

        return 0;
    }