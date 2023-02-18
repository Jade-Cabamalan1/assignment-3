#include "linked_list.h"

template<class T>
void LinkedList<T>::push_front(const T &value) {
    ListNode<T> *curr = head;
    ListNode<T> *temp = curr->next;
    curr-> next = new ListNode<T>(value);
    curr = curr-> next;
    curr-> next = temp;
    num_of_element++;
}

template<class T>
void LinkedList<T>::push_back(const T &value) {
    ListNode<T> *curr = head;
    for (int i = 0; i < num_of_element; ++i) {
        curr = curr->next;
    }
    curr->next = new ListNode<T>(value);
    num_of_element++;
}

template<class T>
void LinkedList<T>::pop_back() {
    if(num_of_element > 0){
        ListNode<T> *curr = head;
        for (int i = 0; i < num_of_element - 1; ++i) {
            curr = curr->next;
        }
        delete (curr->next);
        curr->next = nullptr;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::pop_front() {
    if(num_of_element > 0){
        ListNode<T> *temp = head->next->next;
        delete (head->next);
        head ->next = temp;
        num_of_element--;
    }
}

template<class T>
void LinkedList<T>::remove(T &val) {
    if(num_of_element > 0){
        ListNode<T> *curr = head;
        for (int i = 0; i < num_of_element; ++i) {
            if(curr->next->val == val){
                ListNode<T> *temp = curr->next->next;
                delete (curr->next);
                curr->next = temp;
                num_of_element--;
                i--;
            }
            else {
                curr = curr->next;
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

    ListNode<T> *oldList = head;
    head = new ListNode<T>();

    ListNode<T> *curr = oldList;
    ListNode<T> *otherCurr = otherList->head;
    ListNode<T> *merged = head;

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
    delete oldList;
}

template<class T>
void LinkedList<T>::reverse_iterative() {
    if(num_of_element > 1){
        ListNode<T> *curr = head->next;
        for (int i = 0; i < num_of_element - 1; ++i) {
            ListNode<T> *temp = curr->next->next;
            curr->next->next = head->next;
            head->next = curr->next;
            curr->next = temp;
        }
    }

}