  #define ITERATIONS 1000000L    // number of iterations
    #define FLASH 10000            // blink LED every 1000 iterations
     
    void setup() {
      pinMode(2, OUTPUT);         // set the LED up to blink every 1000 iterations
      Serial.begin(115200);
    }
     
    void loop() {
     
      unsigned long start, time;
      unsigned long niter=ITERATIONS;
      int LEDcounter = 0;
      boolean alternate = false;
      unsigned long i, count=0;
      float x = 1.0;
      float temp, pi=1.0;
     
      Serial.print("Beginning ");
      Serial.print(niter);
      Serial.println(" iterations...");
      Serial.println();
     
      start = millis();  
      for ( i = 2; i < niter; i++) {
        x *= -1.0;
        pi += x / (2.0f*(float)i-1.0f);
        if (LEDcounter++ > FLASH) {
          LEDcounter = 0;
          if (alternate) {
            digitalWrite(2, HIGH);
            alternate = false;
          } else {
            digitalWrite(2, LOW);
            alternate = true;
          }
          delay(1);
        }
      }
      time = millis() - start;
     
      pi = pi * 4.0;
     
      Serial.print("# of trials = ");
      Serial.println(niter);
      Serial.print("Estimate of pi = ");
      Serial.println(pi, 10);
     
      Serial.print("Time: ");
      Serial.print(time);
      Serial.println(" ms");
     
      delay(10000);
    }

