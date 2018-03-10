#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include "cmoothing.h"

bool SMA_init(SMA *sma, int32_t *buffer, uint32_t length)
{
  if (sma == NULL)
  {
    return false;
  }

  if (length == 0) 
  {
    return false;
  }

  if (buffer == NULL)
  {
    return false;
  }

  sma->sum = 0;
  sma->length = length;
  sma->filled = 0;
  sma->data = buffer;
  sma->current_index = 0;
  sma->average = 0;

  return true;
}

double SMA_add(SMA *sma, int32_t value)
{
  if (sma->filled < sma->length)
  {
    sma->filled++;
    sma->data[sma->current_index] = value;
    sma->sum = sma->sum + value;
  }
  else
  {
    sma->sum = sma->sum - sma->data[sma->current_index];
    sma->sum = sma->sum + value;
    sma->data[sma->current_index] = value;
  }

  sma->current_index++;
  if (sma->current_index == sma->length)
  {
    sma->current_index = 0;
  }


  sma->average = sma->sum / sma->filled;
  return sma->average; 
}
