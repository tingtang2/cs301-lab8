#ifndef _CACHE_H_
#define _CACHE_H_

#include <iostream>
#include <cstdlib>
#include <cmath>
#include "Set.h"

using namespace std;


/*
 * This class represents a configurable memory cache.  To configure the
 * cache, the user must specify the cache capacity in bytes, the block
 * size in bytes, and the set-associativity.  The default set-associativity
 * is 1, meaning direct-mapped.
 *
 * The user can add memory accesses to the cache by specifying the byte
 * address for the memory location.  EEach access is assumed to be 4 
 * bytes wide.  
 *
 * The user has the ability to print out the current contents of the cache
 * as well as query the cache about access and hit/miss statistics.
 */
class Cache {
 public:
  /* 
   * This method just creates an instance of the class.  However, there is
   * no default configuration of the class, so the initialize() method must
   * be called to actually create a cache that is properly configured.
   */
  Cache();

  /* Destructor for the class releases all dynamically allocated memory.
   */
  ~Cache();

  /* This method configures the cache.  The capacity and block size need
   * to be specified in bytes.  The set associativity is by default set
   * to 1 (direct mapped) if no argument is specified.  All of the three
   * arguments must be powers of two.  Additionally, the capacity divided
   * by the (block_size * associativity) must not have a fractional 
   * component.  Finally, the method prints out information about the
   * configuration of the cache (see example output files).
   */
  void initialize(int capacity, int block_size, int associativity = 1);  

  /* Adds the address specified as an access to the current cache contents, 
   * potentially evicting an existing entry in the cache.  The address
   * is specified in bytes.
   */
  void addAccess(long long addr);
  
  /* Prints the current contents of the cache.  The output is organized
   * by cache sets and displays the index, tag, valid bit, and lru state.
   */
  void printContents();

  /* Prints the statistics about cache accesses including the number of
   * accesses, hits, misses, and hit rate.
   */
  void printStatistics();

  /* Returns the number of accesses made to the cache. 
   */
  long long getNumberAccesses();

  /* Returns the number of access that resulted in cache misses.
   */
  long long getNumberMisses();

  
 private:
  Set *mySets;
  int myNumSets;
  
  int myCapacity;
  int myBlockSize;
  int myAssociativity;

  int myNumAccesses;
  int myNumHits;
  int myNumMisses;

  /* Returns true if argument is a power of two. Otherwise returns false.
   */
  bool isPowerOfTwo(int val);

};

#endif
