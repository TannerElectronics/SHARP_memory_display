/*
 * Written by Brandon Dunson for Tanner Electronics on May 29th, 2016
 * based on libraries and demos from Adafruit.
 * 
 * check out Adafruit at http://adafruit.com and Tanner's at http://tannerelectronics.com
 * 
 */

// Libraries we lean on
#include <Adafruit_GFX.h>
#include <Adafruit_SharpMem.h>

// Fonts used in the demo
#include <Fonts/FreeSansBold9pt7b.h>
#include <Fonts/FreeSansBoldOblique12pt7b.h>

// any pins can be used
#define CLK 10
#define DI 11
#define CS 12

Adafruit_SharpMem display(CLK, DI, CS);

#define BLACK 0
#define WHITE 1

int count = 0;

void setup(void) 
{
  // start & clear the display
  display.begin();
  display.clearDisplay();

  // Adafruit's module is setup 180 degrees different,
  // this will fix the problem.
  display.setRotation(0);

  // First line of text
  display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(25,1);
  display.println("Tanner's");

  // Second to last line of txt
  display.setCursor(10,75);
  display.println("Hello, world!");

  // Last line of text
  display.setCursor(9,85);
  display.setTextColor(WHITE, BLACK); // 'inverted' text
  display.println(" demo sketch ");
  
  // Third line of text
  display.setTextColor(BLACK);
  display.setFont(&FreeSansBold9pt7b);
  display.setCursor(12,50);
  display.println("Memory");

  // Fourth line of text
  display.setCursor(15,65);
  display.println("Display");  
  
  display.refresh();
}

void loop(void) 
{
  // Incriment variable 'count' at start of each loop
  count++; 

  // If variable 'count' is odd
  // Draw 'SHARP' black (mirror) on white
  if(count%2)
    {
      display.fillRect(0,10,96,24,WHITE);  
      display.setFont(&FreeSansBoldOblique12pt7b);
      display.setCursor(4,30);
      display.setTextColor(BLACK);
      display.println("SHARP");

  // If variable count is even    
  // Draw 'SHARP' white on black (mirror)
    }else{

      display.fillRect(0,10,96,24,BLACK);
      display.setFont(&FreeSansBoldOblique12pt7b);
      display.setCursor(4,30);
      display.setTextColor(WHITE);
      display.println("SHARP");
    
  }
  
  // Display has to be updated to retain visible data
  display.refresh();
  delay(750);
}

