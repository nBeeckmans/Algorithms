#ifndef MAP_HPP
#define MAP_HPP


template<class T>
class Map 
{
  public: 
    Map();
    Map(int numberOfBuckets);
    Map(const Map& map);
    ~Map();
    bool addElement(T element); 
    bool hasElement(T element);
    bool removeElement(T element);

  private:
    int numberOfBuckets;   
};

template <class T>
class Element  
{
  private:
    Element(int key, T value);
    Element(const Element& element);
    ~Element();
    int key;
    T value;
    Element *next;

  friend class Map<T>;
};

template <class T> 
class Bucket 
{
  private: 
    Bucket(int number);
    Bucket(const Bucket& bucket);
    ~Bucket();
    int bucketNumber;
    Element<T>* firstElement;

  friend class Map<T>;
};

#endif
