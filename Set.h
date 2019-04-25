#ifndef _SET_H_
#define _SET_H_

#include <cstdlib>
#include <iostream>
#include "Block.h"

using namespace std;

/* This class represents a set in a cache.  The set associativity for the
 * set is configurable.  
 */
class Set {
 public:

  /* Create a set with no blocks */
  Set();

  /* Deallocate any dynamically allocated memory */
  ~Set();

  /* Specify the number of blocks in a set (i.e. the set associativity) and
  * initialize the set with that number of blocks.
  */
  void initialize(int numBlocks);

  /* Add an access to this tag to the set.  If the tag is not already in the
   * set, add it and return false to indicate a miss.  If the tag is already
   * in the set, access it and return true to indicate a hit.  In both 
   * cases, update the information for the Block accordingly. 
   */
  bool addAccess(long long tag);

  /* Print the contents of the set to stdout.  The argument specifies which
   * set this is in the cache.
   */
  void printSet(int set);

 private:
  Block *myBlocks;
  int myAssociativity;

};


#endif
