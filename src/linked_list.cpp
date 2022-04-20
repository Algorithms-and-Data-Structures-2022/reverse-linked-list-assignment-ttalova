#include "assignment/linked_list.hpp"

#include <utility> // swap

namespace assignment {

  /**
   * Переворачивает связный список, используя три указателя.
   *
   * Сложность
   *    по памяти ~ O(1)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseIterative() {
    Node* cur = front_;
    Node* prev = nullptr;
    Node* next;
    back_ = front_;
    for (int i = 0; i < size_; i++) {
      next = cur -> next;
      cur -> next = prev;
      prev = cur;
      cur = next;
    }
    front_ = prev;
  }

  /**
   * Переворачивает связный список, используя рекурсию.
   *
   * Сложность
   *    по памяти ~ O(N)
   *    по времени ~ O(N)
   */
  void LinkedList::ReverseRecursive() {
    if (size_ > 0) {
      reverse_recursive_helper(front_->next, front_);
      Node* front = front_;
      front_->next = nullptr;
      front_ = back_;
      back_ = front;
    }
  }

  void LinkedList::reverse_recursive_helper(Node*& cur, Node* prev) {
    if (cur == nullptr) {
      return;
    }
    reverse_recursive_helper(cur -> next, cur);
    cur -> next = prev;
  }

}  // namespace assignment
