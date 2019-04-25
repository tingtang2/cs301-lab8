#include "Block.h"

/* This initializes the block as invalid */
Block::Block()
{
  myTag = 0;
  myValid = false;
  myLRU = -1;
}

/* Set the tag of this block */
void Block::setTag(long long tag)
{
  myTag = tag;
}

/* Returns the tag for this block */
long long Block::getTag()
{
  return myTag;
}

/* Set the valid bit for this block */
void Block::setValid(bool valid)
{
  myValid = valid;
}

/* Get the valid bit for this block */
bool Block::getValid()
{
  return myValid;
}

/* Set the LRU value */
void Block::setLRU(int lru)
{
  myLRU = lru;
}

/* Get the LRU value */
int Block::getLRU()
{
  return myLRU;
}
