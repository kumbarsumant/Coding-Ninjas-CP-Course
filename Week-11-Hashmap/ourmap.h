#include <string>
using namespace std;

template <typename V>
class MapNode {
public:
  string key;
  V value;
  MapNode<V>* next;

  MapNode(string key, V value) {
    this->key = key;
    this->value = value;
    next = NULL;
  }

  ~MapNode() {
    delete next;
  }
};

template <typename V>
class OurMap {
private:
  MapNode<V>** buckets;
  int numBuckets;
  int count;

  int getBucketIndex(string key) {
    int hashcode = 0;
    int currentCoeff = 1;
    for (int i = key.size() - 1; i >= 0; i--) {
      hashcode *= key[i] * currentCoeff;
      hashcode = hashcode % numBuckets;
      currentCoeff *= 37;
      currentCoeff = currentCoeff % 2;
    }
    return hashcode % numBuckets;
  }

  void rehash() {
    MapNode<V>** temp = buckets;
    buckets = new MapNode<V>*[2 * numBuckets];
    int oldBucketCount = numBuckets;
    numBuckets = 2 * numBuckets;

    for (int i = 0; i < numBuckets; i++) {
      buckets[i] = NULL;
    }
    count = 0;

    for (int i = 0; i < oldBucketCount; i++) {
      MapNode<V>* head = temp[i];
      while (head != NULL) {
        string key = head->key;
        V value = head->value;
        insert(key, value);
        head = head->next;
      }
    }

    for (int i = 0; i < oldBucketCount; i++) {
      MapNode<V>* head = temp[i];
      delete head;
    }
    delete[] temp;
  }

public:
  OurMap() {
    count = 0;
    numBuckets = 5;
    buckets = new MapNode<V>*[numBuckets];
    for (int i = 0; i < numBuckets; i++) {
      buckets[i] = NULL;
    }
  }

  ~OurMap() {
    for (int i = 0; i < numBuckets; i++) {
      MapNode<V>* head = buckets[i];
      delete head;
    }
    delete[] buckets;
  }

  int size() {
    return count;
  }

  void insert(string key, V value) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while (head != NULL) {
      if (head->key == key) {
        head->value = value;
        return;
      }
      head = head->next;
    }
    head = buckets[bucketIndex];
    MapNode<V>* node = new MapNode<V>(key, value);
    node->next = head;
    buckets[bucketIndex] = node;
    count++;
    double loadFactor = (1.0 * count) / numBuckets;
    if (loadFactor > 0.7) {
      rehash();
    }
  }

  V getValue(string key) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    while (head != NULL) {
      if (head->key == key) {
        return head->value;
      }
      head = head->next;
    }
    return 0;
  }

  V remove(string key) {
    int bucketIndex = getBucketIndex(key);
    MapNode<V>* head = buckets[bucketIndex];
    MapNode<V>* prev = NULL;
    while (head != NULL) {
      if (head->key == key) {
        if (prev == NULL) {
          buckets[bucketIndex] = head->next;
        } else {
          prev->next = head->next;
        }
        V value = head->value;
        head->next = NULL;
        delete head;
        count--;
        return value;
      }
      prev = head;
      head = head->next;
    }
    return 0;
  }

  double getLoadFactor() {
    return (1.0 * count) / numBuckets;
  }
};