#ifndef MAP_HPP
#define MAP_HPP

#include <optional>
#include <variant>

template <typename T> 
class Bucket;
template <typename T>
class Element;

template <typename T>
long unsigned int gethash(T element);


template<typename K, typename V>
class Map 
{
  public: 
    Map();
    Map(int numberOfBuckets);
    Map(const Map& map);
    ~Map();
    bool addKeyValue(K key,V value); 
    bool hasKey(K key);
    std::optional<V>* removeKey(K key);

  private:
    int numberOfBuckets;   
    Bucket<V> *buckets;
};

template <typename T>
class Element  
{
  public :  
    Element(unsigned long int key, T value);
    Element(const Element& element);
    ~Element();
    long unsigned int key;
    T value;
    Element *next;
    Element *previous;
};

template <typename V> 
class Bucket 
{
  public: 
    Bucket();
    Bucket(const Bucket& bucket);
    bool addElementToBucket(Element<V>* element);
    bool hasElement(unsigned long int hash);
    std::optional<V>* removeElement(unsigned long int hash);
    ~Bucket();
    int bucketNumber;
    Element<V>* firstElement;
};



#endif
