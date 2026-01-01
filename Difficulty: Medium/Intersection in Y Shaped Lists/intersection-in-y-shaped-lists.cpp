/*
class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        //  Code Here
        if(head1 == nullptr || head2 == nullptr) return nullptr;
        Node* one = head1;
        Node* two = head2;
        while(one != two) {
            if(one) {
                one = one->next;
            } else {
                one  = head2;
            }
            
            if(two) {
                two = two->next;
            } else {
                two = head1;
            }
        }
        return one;
    }
};