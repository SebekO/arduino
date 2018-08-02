#include <Tlc5940.h>
#include "ClickButton.h"
const int downButtonPin = 8;
const int upButtonPin = 6;
const int midButtonPin = 7;
int ledCount = 13; //liczba aktywnych wyjść (taśm led)
int brightness = 4095; //maksymalna jasność 
int delayTime = 1;
int midStep = 13;
int outs[] = {0,1,2,3,4,5,6,7,8,9,10,11,12}; //wyjścia do których podpinane są taśmy
int outState[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
// Nr. of buttons in the array
const int buttons = 3;
ClickButton button[3] = {
  ClickButton (downButtonPin, LOW, CLICKBTN_PULLUP),
  ClickButton (upButtonPin, LOW, CLICKBTN_PULLUP),
  ClickButton (midButtonPin, LOW, CLICKBTN_PULLUP),
};
int LEDfunction[buttons]  = { 0, 0, 0 };
const int DOWN_BUTTON = 0;
const int UP_BUTTON = 1;
const int MID_BUTTON = 2;
const int STAN_WYLACZONY = 0;
const int STAN_ROZJASNIANIE_OD_DOLU = 1;
const int STAN_SCIEMNIANIE_OD_DOLU = 2;
const int STAN_ROZJASNIANIE_OD_GORY = 3;
const int STAN_SCIEMNIANIE_OD_GORY = 4;
const int STAN_ROZJASNIANIE_OD_SRODKA = 5;
const int STAN_SCIEMNIANIE_OD_SRODKA = 6;
const int STAN_ROZJASNIANIE_CALOSCI = 7;
const int STAN_SCIEMNIANIE_CALOSCI = 8;
const int STAN_WLACZONY = 9;

const int SCIEMNIANIE_POJEDYNCZE_STEP = 5;
const int SCIEMNIANIE_CALOSCI_STEP = 10;
const int ROZJASNIANIE_POJEDYNCZE_STEP = 25;
const int ROZJASNIANIE_CALOSCI_STEP = 10;
int STAN = STAN_WYLACZONY;
void setup()
{

  Tlc.init();
  for (int i=0; i<buttons; i++)
  {
    // Setup button timers (all in milliseconds / ms)
    // (These are default if not set, but changeable for convenience)
    button[i].debounceTime   = 20;   // Debounce timer in ms
    button[i].multiclickTime = 250;  // Time limit for multi clicks
    button[i].longClickTime  = 800; // Time until long clicks register
  }    
   updateLed();

}


void loop()
{
  
for (int i=0; i<buttons; i++) {
    // Update state of all buitton
    button[i].Update();
  
    // Save click codes in LEDfunction, as clicks counts are reset at next Update()
    if (button[i].clicks != 0) LEDfunction[i] = button[i].clicks;
  
      // Simply toggle LED on single clicks
    // (Cant use LEDfunction like the others here,
    //  as it would toggle on and off all the time)
    if(button[i].clicks == 1) {
      wlaczPianino(i);
    }

    // slow blink (must hold down button. 1 second long blinks)
    if(LEDfunction[i] == -1) {
      ustawStanStaly(i);
      LEDfunction[i] = 0;
    }
  }  
  
  updateCircuitState(); 
  updateLed();
   delay(delayTime);  
}

void updateLed() {
   for (byte diode = 0; diode<ledCount;diode++) {
     Tlc.set(outs[diode], brightness-outState[diode]);
    }
    Tlc.update();
}

void updateCircuitState() {
  if (STAN == STAN_ROZJASNIANIE_OD_DOLU) {
    rozjasnianieOdDolu();
  }
  if (STAN == STAN_SCIEMNIANIE_OD_DOLU) {
    sciemnianieOdDolu();
  }

  if (STAN == STAN_ROZJASNIANIE_OD_GORY) {
    rozjasnianieOdGory();
  }
  if (STAN == STAN_SCIEMNIANIE_OD_GORY) {
    sciemnianieOdGory();
  }
  if (STAN == STAN_ROZJASNIANIE_CALOSCI) {
    rozjasnianieCalosci();
  }
  if (STAN == STAN_SCIEMNIANIE_CALOSCI) {
    sciemnianieCalosci();
  }

  if (STAN == STAN_ROZJASNIANIE_OD_SRODKA) {
    rozjasnianieOdSrodka();
  }
  if (STAN == STAN_SCIEMNIANIE_OD_SRODKA) {
    sciemnianieOdSrodka();
  }

}

void rozjasnianieOdSrodka() {
  bool changed = false;

  for (int diode = midStep; diode<ledCount;diode++) {   
    if (outState[diode] < brightness) {
      int newState = outState[diode];
      newState = newState + ROZJASNIANIE_POJEDYNCZE_STEP;
      if (newState > brightness) {
        newState = brightness;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
  }
  for (int diode = midStep-1; diode>=0;diode--) {   
    if (outState[diode] < brightness) {
      int newState = outState[diode];
      newState = newState + ROZJASNIANIE_POJEDYNCZE_STEP;
      if (newState > brightness) {
        newState = brightness;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
    
  }
      if (!changed) {
      STAN = STAN_SCIEMNIANIE_OD_SRODKA;
    }    

}

void sciemnianieOdSrodka() {
 bool changed = false;

  for (int diode = midStep; diode<ledCount;diode++) {   
    if (outState[diode] > 0) {
      int newState = outState[diode];
      newState = newState - SCIEMNIANIE_POJEDYNCZE_STEP;
      if (newState < 0 ) {
        newState = 0;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
  }
  for (int diode = midStep-1; diode>=0;diode--) {   
    if (outState[diode] > 0) {
      int newState = outState[diode];
      newState = newState - SCIEMNIANIE_POJEDYNCZE_STEP;
      if (newState < 0) {
        newState = 0;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
    
     
  }
   if (!changed) {
      STAN = STAN_WYLACZONY;
    }  
}

void rozjasnianieCalosci() {
  bool changed = false;
  for (int diode = 0; diode<ledCount;diode++) {   
    if (outState[diode] < brightness) {
      int newState = outState[diode];
      newState = newState + ROZJASNIANIE_CALOSCI_STEP;
      if (newState > brightness) {
        newState = brightness;
      }
      outState[diode] = newState;
      changed = true;
    }
    
     
  }
   if (!changed) {
      STAN = STAN_WLACZONY;
    }  
}

void sciemnianieCalosci() {
  bool changed = false;
  for (int diode = 0; diode<ledCount;diode++) {   
    if (outState[diode] > 0) {
      int newState = outState[diode];
      newState = newState - SCIEMNIANIE_CALOSCI_STEP;
      if (newState < 0) {
        newState = 0;
      }
      outState[diode] = newState;
      changed = true;

    }
    
   
  }
   if (!changed) {
      STAN = STAN_WYLACZONY;
    }    
}

void rozjasnianieOdDolu() {
  bool changed = false;
  for (int diode = 0; diode<ledCount;diode++) {   
    if (outState[diode] < brightness) {
      int newState = outState[diode];
      newState = newState + ROZJASNIANIE_POJEDYNCZE_STEP;
      if (newState > brightness) {
        newState = brightness;
      
      }
      outState[diode] = newState;
      changed = true;
      break;
    }    
  }
    if (!changed) {
      STAN = STAN_SCIEMNIANIE_OD_DOLU;
    }    

}

void sciemnianieOdDolu() {
  bool changed = false;
  for (int diode = 0; diode<ledCount;diode++) {   
    if (outState[diode] > 0) {
      int newState = outState[diode];
      newState = newState - SCIEMNIANIE_POJEDYNCZE_STEP;
      if (newState < 0) {
        newState = 0;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
    
   }
    if (!changed) {
      STAN = STAN_WYLACZONY;
    }    

}

void rozjasnianieOdGory() {
  bool changed = false;
  for (int diode = ledCount-1; diode>=0;diode--) {   
    if (outState[diode] < brightness) {
      int newState = outState[diode];
      newState = newState + ROZJASNIANIE_POJEDYNCZE_STEP;
      if (newState > brightness) {
        newState = brightness;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
    
        
  }
  if (!changed) {
      STAN = STAN_SCIEMNIANIE_OD_GORY;
    }
}

void sciemnianieOdGory() {
  bool changed = false;
  for (int diode = ledCount-1; diode>=0;diode--) {   
    if (outState[diode] > 0) {
      int newState = outState[diode];
      newState = newState - SCIEMNIANIE_POJEDYNCZE_STEP;
      if (newState < 0) {
        newState = 0;
      }
      outState[diode] = newState;
      changed = true;
      break;
    }
    
  }
     if (!changed) {
      STAN = STAN_WYLACZONY;
    }    
 
}

void wlaczPianino(int button) {
  /*
  jesli swiatla byly wlaczone, tylko plynnie wylaczamy
  */
  if (STAN == STAN_WLACZONY) {
      if (button == DOWN_BUTTON) {
        STAN = STAN_SCIEMNIANIE_OD_DOLU;
      }
      if (button == UP_BUTTON) {
        STAN = STAN_SCIEMNIANIE_OD_GORY;
      }
      if (button == MID_BUTTON) {
        STAN = STAN_SCIEMNIANIE_OD_SRODKA;
      }
  }
  
  /*
  jesli swiatla byly wylaczone, wtedy plynnie wlaczamy
  */
    if (STAN == STAN_WYLACZONY) {
      if (button == DOWN_BUTTON) {
        STAN = STAN_ROZJASNIANIE_OD_DOLU;
      }
      if (button == UP_BUTTON) {
        STAN = STAN_ROZJASNIANIE_OD_GORY;
      }
      if (button == MID_BUTTON) {
        STAN = STAN_ROZJASNIANIE_OD_SRODKA;
      }
  }

}

void ustawStanStaly(int button) {
    Serial.print("ustawStanStaly ");
  Serial.print(button);
  Serial.print(" ");
  Serial.println(STAN);
  if (
      STAN == STAN_WLACZONY ||
      STAN == STAN_SCIEMNIANIE_OD_DOLU ||      
      STAN == STAN_SCIEMNIANIE_OD_GORY ||            
      STAN == STAN_SCIEMNIANIE_OD_SRODKA            
      ) {
    STAN = STAN_SCIEMNIANIE_CALOSCI;
  }
  
  if (
      STAN == STAN_WYLACZONY ||
      STAN == STAN_ROZJASNIANIE_OD_DOLU ||      
      STAN == STAN_ROZJASNIANIE_OD_GORY ||            
      STAN == STAN_ROZJASNIANIE_OD_SRODKA            
     ) {
    STAN = STAN_ROZJASNIANIE_CALOSCI;
  }
}
