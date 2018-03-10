#include <minunit.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cmoothing.h>

MU_TEST(sma_init)
{
  uint32_t length = 3;
  int32_t buffer[length];
  SMA sma;

  if (SMA_init(NULL, NULL, 0))
  {
    mu_fail("should not init null SMA struct");
    return;
  }

  if (SMA_init(&sma, NULL, 0))
  {
    mu_fail("should not init sma with null buffer"); 
    return;
  }

  if (SMA_init(&sma, buffer, 0))
  {
    mu_fail("should not init sma with zero length buffer");
    return;
  }

  if (!SMA_init(&sma, buffer, length))
  {
    mu_fail("failed to init sma");
    return;
  }
}

MU_TEST(sma_add)
{
  double res = 0;
  uint32_t length = 3;
  int32_t buffer[length];
  SMA sma;

  if (!SMA_init(&sma, buffer, length))
  {
    mu_fail("failed to init sma");
    return;
  }

  res = SMA_add(&sma, 3);
  if (res != 3)
  {
    mu_fail("failed to calculate average");
    return;
  }

  res = SMA_add(&sma, 7);
  if (res != 5)
  {
    mu_fail("failed to calculate average");
    return;
  }

  res = SMA_add(&sma, 11);
  if (res != 7)
  {
    mu_fail("failed to calculate average");
    return;
  }

  res = SMA_add(&sma, 6);
  if (res != 8)
  {
    mu_fail("failed to calculate average");
    return;
  }


  res = SMA_add(&sma, 1);
  if (res != 6)
  {
    mu_fail("failed to calculate average");
    return;
  }
  
  res = SMA_add(&sma, 8);
  if (res != 5)
  {
    mu_fail("failed to calculate average");
    return;
  }

}

MU_TEST_SUITE(test_suite)
{
  MU_RUN_TEST(sma_init);
  MU_RUN_TEST(sma_add);
}

int main()
{
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return 0;
}
