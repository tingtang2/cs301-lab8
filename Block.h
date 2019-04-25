#ifndef _BLOCK_H_
#define _BLOCK_H_

/* This class represents a single cache block.  It will include the
 * tag information for the block, valid information, and LRU information.
 */
class Block{
 public:
  /* This initializes the block as invalid */
  Block();

  /* Set the tag of this block */
  void setTag(long long tag);

  /* Returns the tag for this block */
  long long getTag();

  /* Set the valid bit for this block */
  void setValid(bool valid);

  /* Get the valid bit for this block */
  bool getValid();

  /* Set the LRU value */
  void setLRU(int lru);

  /* Get the LRU value */
  int getLRU();

 private:
  long long myTag;
  bool myValid;
  int myLRU;   // 0 = mru

};

#endif
