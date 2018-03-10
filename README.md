# cmoothing

For smoothing values.

## Setup

### Submodules
Fetch submodules.

`git submodules init`

`git submodules update`

### Building
Build via make.

`make` or `make build`


### Test
Test via make.

`make test`

### Distribute
Create static library via make.

`make static`


### Clean
Clean workspace via make

`make clean`

## Example

```c
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.b>
#include <cmoothing.h>

int main()
{
  uint32_t length = 3;
  int32_t buffer[length];
  SMA sma;

  // Create a simple moving average with a window of 3
  if (!SMA_init(&sma, buffer, length))
  {
    // something wrong with init params 
    return 1;
  }

  double new_average = SMA_add(&sma, 10);
  new_average = SMA_add(&sma, 3);
  new_average = SMA_add(&sma, 5);

  // ...

  return 0;
}

```
