#include "map.hpp"
#include <cstring>
#include <iostream>


template<typename K, typename V>
Map<K,V>::Map() 
{
  numberOfBuckets = 100;
  buckets = new Bucket<V>[numberOfBuckets];
  for (int i = 0; i < this->numberOfBuckets; i++)
  {
    this->buckets[i].bucketNumber = i;
  }
}

template<typename K, typename V>
Map<K, V>::Map(int numberOfBuckets) 
{
  this->numberOfBuckets = numberOfBuckets;
  buckets = new Bucket<V>[numberOfBuckets];
  for (int i = 0; i < this->numberOfBuckets; i ++) 
  {
    this->buckets[i].bucketNumber = i;
  }
}

template<typename K, typename V>
Map<K,V>::Map(const Map& map) 
{
  this->numberOfBuckets = map.numberOfBuckets;
  this->buckets = new Bucket<V>[map.numberOfBuckets];
  for (int i = 0; i < this->numberOfBuckets; i++) 
  {
    this->buckets[i] = *(new Bucket<V>(map.buckets[i])); 
  }
}

template <typename K,typename V>
bool Map<K,V>::addKeyValue(K keyToAdd, V valueToAdd) 
{
  unsigned long int hash = gethash(keyToAdd);
  Element<V> *element = new Element<V>(hash, valueToAdd);
  int bucketNumberToChoose = hash % this->numberOfBuckets;
  return this->buckets[bucketNumberToChoose].addElementToBucket(element);
}

template <typename K, typename V>
bool Map<K,V>::hasKey(K toCheck) 
{
  unsigned long int hash = gethash(toCheck);
  int bucketNumberToCheck = hash % this->numberOfBuckets;
  return this->buckets[bucketNumberToCheck].hasElement(hash);
}

template <typename K, typename V>
std::optional<V>* Map<K,V>::removeKey(K key) 
{
  unsigned long int hash = gethash(key);
  int bucketNumberToCheck = hash % this->numberOfBuckets;
  Bucket<V> bucket = this->buckets[bucketNumberToCheck];
  return bucket.removeElement(hash);
}

template<typename K, typename V>
Map<K, V>::~Map() 
{
  
  delete []buckets;
}

template<typename V>
Bucket<V>::Bucket()
{
  this->bucketNumber = 0;
  this->firstElement = nullptr;
}

template<typename V>
Bucket<V>::Bucket(const Bucket& bucket) 
{
  this->bucketNumber = bucket.bucketNumber;
  if (bucket.firstElement)
    this->firstElement = new Element<V>(*bucket.firstElement);
  else 
    return;

  Element<V> *currentOtherBucketElement = bucket.firstElement;
  Element<V> *currentElement = this->firstElement;
  while(currentOtherBucketElement->next != nullptr)
  {
    Element<V> *newlyCreatedElement = new Element<V>(*currentOtherBucketElement);
    currentElement->next = newlyCreatedElement;
    newlyCreatedElement->previous = currentElement;
    currentElement = currentElement->next;
    currentOtherBucketElement = currentOtherBucketElement->next;
  }
}

template<typename V>
bool Bucket<V>::addElementToBucket(Element<V>* element)
{
  if (this->firstElement == nullptr)   
  {
    this->firstElement = element;
    return true;
  }

  Element<V>* currentElement = this->firstElement;
  while (currentElement->next != nullptr) 
  {
    if (currentElement->value == element->value)
    {
      return false;
    }
    currentElement = currentElement->next;
  }
  element->previous = currentElement;
  currentElement->next = element;
  

  return true;
}

template<typename V>
Bucket<V>::~Bucket()
{
  Element<V> *nextElement = this->firstElement;
  while (nextElement) 
  {
    Element<V> *currentElement = nextElement; 
    nextElement = currentElement->next;
    delete currentElement;
  }
}

template<typename V>
bool Bucket<V>::hasElement(unsigned long int hash)
{
  Element<V> *nextElement = this->firstElement;
  while (nextElement != nullptr)
  {
    Element<V> *currentElement = nextElement;
    nextElement = currentElement->next;
    if (currentElement->key == hash) 
    {
      return true;
    }
  }

  return false; 
}

template<typename V>
std::optional<V>* Bucket<V>::removeElement(unsigned long int hash) 
{
  if (!this->firstElement) 
  {
    return new std::optional<V>();
  }

  if (this->firstElement->key == hash) 
  {
    std::cout << "inside first element thingy" << std::endl;
    std::optional<V>* optional = new std::optional<V>(this->firstElement->value);
    if (this->firstElement->next) 
    {
      this->firstElement = this->firstElement->next;
    }
    else 
    {
      this->firstElement = nullptr;
    }

    delete this->firstElement;
    return optional;
  }

  Element<V> *currentElement = this->firstElement;

  while (currentElement)
  {
    std::cout << "other elements thingy" << std::endl;
    if (currentElement->key == hash)
    {
      std::optional<V>* optional = new std::optional<V>(currentElement->value);
      delete currentElement;
      return optional;
    }
    currentElement = currentElement->next;
  }

  return new std::optional<V>();
}

template<typename V>
Element<V>::Element(const Element<V>& element)
: key(element.key), value(element.value)
{
  this->previous = nullptr;
  this->next = nullptr;
}

template<typename V>
Element<V>::Element(unsigned long int _key, V _value)
{ 
  this->key = _key;
  this->value = _value;
  next = nullptr;
  previous = nullptr;
}

template<typename V>
Element<V>::~Element()
{
  if (this->next != nullptr && this->previous != nullptr) 
  {
    this->next->previous = this->previous;
    this->previous->next = this->next;
    return;
  }

  if (this->next != nullptr)
  {
    this->next->previous = nullptr;
  }
  
  if (this->previous != nullptr)
  {
    this->previous->next = nullptr;
  }
}

// implementation for strings specifically
template<>
long unsigned int gethash(char* string) 
{
  unsigned long hash = 5381;
  int size = strlen(string);
  int c;
  int i = 0;

  while (i < size) { 
    c = string[i];
    hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    i ++;
  }
  std::cout << hash << std::endl;
  return hash;
}

// no hashing required for integers (not sure if that's the greatest idea)
template<>
long unsigned int gethash(int integer)
{
  return (long unsigned int)integer;
}

template class Map<char*,double>;
template class Bucket<double>;
template class Element<double>;
