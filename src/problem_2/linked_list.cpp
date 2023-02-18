#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    //creates a new node, sets that as next of head.
    ListNode<T> *next = head->next;
    head-> next = new ListNode<T>(value);
    //sets old next as the next of the new node
    head-> next->next = next;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *curr = head;
    //goes to the end of the list
    for (int i = 0; i < num_of_element && curr->next != nullptr; ++i) {
        curr = curr->next;
    }
    //creates new node
    curr->next = new ListNode<T>(value);
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    //if list is empty, does nothing
    if(num_of_element > 0){
        ListNode<T> *curr = head;
        //goes to second last element in the list
        for (int i = 0; i < num_of_element - 1; ++i) {
            curr = curr->next;
        }
        //deletes last member of list and sets next to nullptr
        delete (curr->next);
        curr->next = nullptr;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::pop_front() {
    //if list is empty, does nothing
    if(num_of_element > 0){
        //delets first element, then sets second element as first element
        ListNode<T> *temp = head->next->next;
        delete (head->next);
        head ->next = temp;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::remove(T &val) {
    //if list is empty does nothing
    if(num_of_element > 0){
        ListNode<T> *curr = head;
        //goes through each node in the list
        for (int i = 0; i < num_of_element;) {
            //if next node is equal to target value, save the following node delete next node and set next to following node
            if(curr->next->val == val){
                ListNode<T> *temp = curr->next->next;
                delete (curr->next);
                curr->next = temp;
                num_of_element--;
            }
            //else goes to next node
            else {
                curr = curr->next;
                i++;
            }
        }
    }
}

/*
 * merge in ascending order
 */
template<class T>
void LinkedList<T>::merge(const List<T> &ot) {
    const List<T> *ptr = &ot;
    const LinkedList<T> *otherList = dynamic_cast<const LinkedList<T> *>(ptr);

    num_of_element += otherList->num_of_element;
    //creates new list and saves old list for navigating/deletion
    ListNode<T> *oldList = head;
    head = new ListNode<T>();
    //pointers to navigate each list
    ListNode<T> *curr = oldList;
    ListNode<T> *otherCurr = otherList->head;
    ListNode<T> *merged = head;
    //goes through each node on both lists, adding to the merged list in ascending order
    while(curr->next != nullptr && otherCurr->next != nullptr){
        if(curr->next->val < otherCurr->next->val){
            merged->next = new ListNode(curr->next->val);
            merged = merged->next;
            curr = curr->next;
        }
        else{
            merged->next = new ListNode(otherCurr->next->val);
            merged = merged->next;
            otherCurr = otherCurr->next;
        }
    }
    //adding remaining nodes to merged list
    while(curr->next != nullptr){
        merged->next = new ListNode(curr->next->val);
        merged = merged->next;
        curr = curr->next;
    }
    while(otherCurr->next != nullptr){
        merged->next = new ListNode(otherCurr->next->val);
        merged = merged->next;
        otherCurr = otherCurr->next;
    }
    //list no longer needed, ready for deletion
    delete oldList;
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    //only works if the list has at least 2 nodes
    if(num_of_element > 1){
        //curr is the original first node.sets curr.next as the first node of list and sets the following node as curr next node
        ListNode<T> *curr = head->next;
        for (int i = 0; i < num_of_element - 1; ++i) {
            ListNode<T> *following = curr->next->next;
            curr->next->next = head->next;
            head->next = curr->next;
            curr->next = following;
        }
    }

}