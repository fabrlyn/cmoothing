#ifndef CMOOTHING_H
#define CMOOTHING_H

typedef struct SMA {
  uint32_t length;
  uint32_t filled;
  int32_t *data;
  int32_t sum;
  uint32_t current_index;
  double average;
} SMA;

bool SMA_init(SMA *sma, int32_t *buffer, uint32_t length);
double SMA_add(SMA *sma, int32_t value);

void router_test();

#endif
