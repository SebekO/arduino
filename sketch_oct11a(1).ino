#include <Tlc5940.h>

void setup()
{
  Tlc.init();

  Tlc.set(1, 4095);
  Tlc.set(2, 4095);
  Tlc.set(3, 4095);
  Tlc.set(4, 4095);
  

  while (Tlc.update());
}

void loop()
{
}
