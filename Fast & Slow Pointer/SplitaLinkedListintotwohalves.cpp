// Given a Circular linked list. The task is split into two Circular Linked lists.If there are an odd
// number of nodes in the given circular linked list then out of the resulting two halved lists, 
// the first list should have one node more than the second list.

// Examples :

// Input: LinkedList : 10->4->9
// Output: 10->4 , 9
// Explanation: After dividing linked list into 2 parts , the first part contains 10, 4 and 
// second part contain only 9.


// Input: LinkedList : 10->4->9->10
// Output: 10->4 , 9->10
// Explanation: After dividing linked list into 2 parts , the first part contains 10, 4 
// and second part contain 9, 10.

#include <bits/stdc++.h>
using namespace std;

// The structure of linked list is the following
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }
};


//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

class Solution {
  public:
    pair<Node *, Node *> splitList(struct Node *head) {
        // code here
        Node *slow = head;
        Node *fast = head->next;
        
        while(fast != head && fast->next != head){
            slow = slow->next;
            fast = fast->next;
            
            if(fast->next != head){
                fast = fast->next;
            }
        }
        
        fast->next = slow->next;
        slow->next = head;
        
        return pair<Node *, Node *> {head, fast->next};
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < n - 1; i++) {
            cin >> data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        tail->next = head;

        Solution ob;
        pair<Node *, Node *> result = ob.splitList(head);
        Node *head1 = result.first;
        Node *head2 = result.second;

        Node *temp = head1;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head1);
        cout << endl;

        temp = head2;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head2);
        cout << endl;
    }
    return 0;
}