#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::push_back(const std::string& val) {
  // create new node
  ULListStr::Item* n = new ULListStr::Item();
  n -> first = 0;
  n -> last = 0;
  n -> prev = n -> next = NULL;
  
  // empty case
  if (tail_ == NULL) {
    head_ = tail_ = n;
    tail_ -> first = tail_ -> last = ARRSIZE/2;
  }
  else if (tail_ -> last == ARRSIZE) {
    n -> prev = tail_;
    tail_ -> next = n;
    tail_ = n;
  }
  else {
    delete n;
  }

  tail_ -> val[tail_ -> last] = val;
  tail_ -> last++;
  size_++;
}

void ULListStr::push_front(const std::string& val) {
  ULListStr::Item* n = new ULListStr::Item();
  n -> first = 0;
  n -> last = 0;
  n -> prev = n -> next = nullptr;

  if (head_ == nullptr) {
    head_ = tail_ = n;
    head_ -> first = tail_ -> last = ARRSIZE/2;
  }
  else if (head_ -> first == 0){
    n -> first = n -> last = ARRSIZE;
    n -> next = head_;
    head_ -> prev = n;
    head_ = n;
  }
  else {
    delete n;
  }
  head_ -> first--;
  head_ -> val[head_ -> first] = val;
  size_++;
}

void ULListStr::pop_back() {
  if (size_ == 0) return;
  tail_ -> last--;
  size_--;
  if (tail_ -> last == tail_ -> first) {
    Item* remove = tail_;
    tail_ = tail_ -> prev;
    if (tail_ != nullptr) tail_ -> next = nullptr;
    else head_ = nullptr;
    delete remove;
  }
}

void ULListStr::pop_front() {
  if (size_ == 0) return;
  head_ -> first++;
  size_--;
  if (head_ -> last == head_ -> first) {
    Item* remove = head_;
    head_ = head_ -> next;
    if (head_ != nullptr) head_ -> prev = nullptr;
    else tail_ = nullptr;
    delete remove;
  }
}

std::string const& ULListStr::front() const {
  if (size_ == 0) {
    throw std::out_of_range("Front is empty");
  }
  return head_ -> val[head_ -> first];
}

std::string const& ULListStr::back() const {
  if (size_ == 0) {
    throw std::out_of_range("Back is empty");
  }
  return tail_ -> val[tail_ -> last - 1];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  if (loc >= size_) return nullptr;
  Item* curr = head_;
  size_t index = loc;
  while (curr != nullptr) {
    size_t looked = curr -> last - curr -> first;
    if (index < looked) {
      return &curr -> val[curr -> first + index];
    }
    index -= looked;
    curr = curr -> next;
  }
  return nullptr;
}

void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
