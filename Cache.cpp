#include "Cache.h"

/* 
 * This method just creates an instance of the class.  However, there is
 * no default configuration of the class, so the initialize() method must
 * be called to actually create a cache that is properly configured.
 */
Cache::Cache()
{
  mySets = 0;
  myNumSets = 0;

  myNumAccesses = myNumHits = myNumMisses = 0;
  myCapacity = myBlockSize = myAssociativity = 0;
}

/* Destructor for the class releases all dynamically allocated memory.
 */
Cache::~Cache()
{
  if(mySets != 0){
    delete [] mySets;
  }
}

/* This method configures the cache.  The capacity and block size need
 * to be specified in bytes.  The set associativity is by default set
 * to 1 (direct mapped) if no argument is specified.  All of the three
 * arguments must be powers of two.  Additionally, the capacity divided
 * by the (block_size * associativity) must not have a fractional 
 * component.  Finally, the method prints out information about the
 * configuration of the cache (see example output files).
 */
void Cache::initialize(int capacity, int block_size, int associativity)
{
  myCapacity = capacity;
  myBlockSize = block_size;
  myAssociativity = associativity;

  if(isPowerOfTwo(capacity) == false){
    cerr << "Cache capacity has to be power of 2 " << endl;
    exit(1);
  }
  if(isPowerOfTwo(block_size) == false){
    cerr << "Cache block size has to be power of 2 " << endl;
    exit(1);
  }
  if(isPowerOfTwo(associativity) == false){
    cerr << "Associativity needs to be a power of 2 " << endl;
    exit(1);
  }

  if( (capacity % (block_size * associativity)) != 0 || (capacity / (block_size * associativity)) == 0){
    cerr << "Block size * associativity must divide evenly into capacity " << endl;
    exit(1);
  }

  myNumSets = capacity / (block_size * associativity);
  mySets = new Set[myNumSets];
  
  for(int i = 0; i < myNumSets; i++){
    mySets[i].initialize(myAssociativity);
  }

  cout << "Capacity " << dec << myCapacity << endl;
  cout << "Block size " << dec << myBlockSize << endl;
  cout << "Associativity " << dec << myAssociativity << endl;
  cout << "Num Sets " << dec << myNumSets << endl;

}

/* Adds the address specified as an access to the current cache contents, 
 * potentially evicting an existing entry in the cache.  The address
 * is specified in bytes.
 */
void Cache::addAccess(long long addr)
{
  long long blockAddress = addr/myBlockSize; // computes block address
  int index = blockAddress % myNumSets; // computers index 
  long long tag = blockAddress/myNumSets; // computes tag

  if (mySets[index].addAccess(tag))
      myNumHits++;
  else
      myNumMisses++;

  myNumAccesses++;

}

/* Prints the current contents of the cache.  The output is organized
 * by cache sets and displays the index, tag, valid bit, and lru state.
 */
void Cache::printContents()
{
  for(int i = 0; i < myNumSets; i++){
    mySets[i].printSet(i);
  }
}

/* Prints the statistics about cache accesses including the number of
 * accesses, hits, misses, and hit rate.
 */
void Cache::printStatistics()
{
  cout << "ACCESSES " << dec << myNumAccesses << endl;
  cout << "HITS " << dec << myNumHits << endl;
  cout << "MISSES " << dec << myNumMisses << endl;
  cout << "HIT RATE " << ( (float)myNumHits / (float) myNumAccesses) << endl;

}

/* Returns the number of accesses made to the cache. 
 */
long long Cache::getNumberAccesses()
{
  return myNumAccesses;
}

/* Returns the number of access that resulted in cache misses.
 */
long long Cache::getNumberMisses()
{
  return myNumMisses;
}

/* Returns true if argument is a power of two. Otherwise returns false.
 */
bool Cache::isPowerOfTwo(int val)
{
  if(val >= 1){
    int curPow = 1;
    while(curPow <= val){
      if(val == curPow){
	return true;
      }
      curPow *= 2;
    }
  }
  return false;
}
