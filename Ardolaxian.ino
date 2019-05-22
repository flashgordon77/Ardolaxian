// (c)Gordon D. 2018
// Atari Galaxien simulation
// Use it for your convenince



#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>



#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2
#define SSD1306_128_64


unsigned long currentTime;
unsigned long loopTime;
unsigned char encoder_A;
unsigned char encoder_B;
unsigned char encoder_A_prev = 0;
int brightness = 0;
int fadeAmount = 0;
int LED = 0;
int looping;
int start = 0;
int x[10];
int y[10];
int i = 0;
int z = 0;
int spacex = 0;
int spacei = 0;
int spaceleftbound = 0;
int spacerightbound = 120;
int starsy[20];
int starsx[20];
int alieny = 3;
int shootx = 0;
int shooty = 56;
int shoot = 0;
int count = 0;
int fallingalien = 0;
int fallingalienx = 0;
int fallingalieny = 10;
int collision = 0;
int Highscore[7];
int Level = 1;
int gamenumber = 0; // variable for the Highscoredisplay increase gamenumber after each 5 rows


void setup()  {
  randomSeed(analogRead(0));
  pinMode(LED_BUILTIN, OUTPUT);


  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();

  pinMode(11, INPUT);
  pinMode(12, INPUT);
  pinMode(13, INPUT);
  currentTime = millis();
  loopTime = currentTime;



  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("ATARI CORP. (c)1982");
  display.display();
  delay(1400);

  display.setCursor(3, 0);
  display.clearDisplay();
  display.println("READY");
  display.display();

  for (int z = 0; z < 8; z++) { // write the alien draw space
    x[z] = x[z] + 15 * z;
  }

  for (int z = 0; z < 20; z++) { // star x value
    starsx[z] = random(128);
  }
  for (int z = 0; z < 20; z++) { // star y value
    starsy[z] = random(13, 64);
  }
}
void loop()  {

  start++;
  if (start < 120) { // start startseqence
    display.setTextSize(0);
    display.setCursor(3, 0);
    display.println("READY");
    looping++;
    if (looping <= 15)
    {
      display.fillRect(3, 11, 7, 10, WHITE);
      display.display();
    }
    if (looping <= 30 && looping >= 15)
    {
      display.fillRect(3, 11, 7, 10, BLACK);
      display.display();
    }

    if (looping == 30)
    {
      looping = 0;
    }


  }
  {
    digitalWrite(LED_BUILTIN, HIGH);
  } // End Starsequence
  if (start == 900) { // clearscreen
    display.clearDisplay();
  }
  if (start > 900) { // gamesequence
    {
      digitalWrite(LED_BUILTIN, HIGH);



      // galaxian alien drawroutine

      //pos up

      if (start >= 1001 && start <= 1006)
      { for (int z = 0; z < 10; z++) {

          /*
            display.setCursor(0, 20);
            display.println(i);
             display.setCursor(0, 30);
            display.println(z);
            display.setCursor(0, 40);
            display.println(x[z]);
             display.display();
            delay(500);
            display.clearDisplay();
          */

          display.fillRect(0 + x[z], 0 + 13, 13, 13, BLACK); //clear screen
          display.drawPixel(4 + x[z], 1 + alieny + 13, WHITE); // horn left
          display.drawPixel(6 + x[z], 1 + alieny + 13, WHITE); // horn right
          display.drawPixel(1 + x[z], 2 + alieny + 13, WHITE); //finger left
          display.drawPixel(9 + x[z], 2 + alieny + 13, WHITE); //finger right
          display.drawPixel(1 + x[z], 3 + alieny + 13, WHITE); //arm left
          display.drawPixel(2 + x[z], 3 + alieny + 13, WHITE); //arm left
          display.drawPixel(3 + x[z], 3 + alieny + 13, WHITE); //arm left
          display.drawPixel(7 + x[z], 3 + alieny + 13, WHITE); //arm right
          display.drawPixel(8 + x[z], 3 + alieny + 13, WHITE); //arm right
          display.drawPixel(9 + x[z], 3 + alieny + 13, WHITE); //arm right
          display.fillRect(4 + x[z], 2 + alieny + 13, 3, 3, WHITE); //body
          display.drawPixel(3 + x[z], 5 + alieny + 13, WHITE); //leg left
          display.drawPixel(4 + x[z], 5 + alieny + 13, WHITE); //leg left
          display.drawPixel(3 + x[z], 6 + alieny + 13, WHITE); //leg left
          display.drawPixel(2 + x[z], 6 + alieny + 13, WHITE); //leg left
          display.drawPixel(6 + x[z], 5 + alieny + 13, WHITE); //leg right
          display.drawPixel(7 + x[z], 5 + alieny + 13, WHITE); //leg right
          display.drawPixel(8 + x[z], 6 + alieny + 13, WHITE); //leg right
          display.drawPixel(9 + x[z], 6 + alieny + 13, WHITE); //leg right
          display.drawPixel(4 + x[z], 3 + alieny + 13, BLACK); //eye left
          display.drawPixel(6 + x[z], 3 + alieny + 13, BLACK); //eye right
        }
        display.display();
      }// end drawing loop up

      //pos down
      if (start >= 1007 && start <= 1014)
      {
        for (int z = 0; z < 10; z++) {
          display.fillRect(0 + x[z], 0 + 13, 13, 13, BLACK); //clear screen
          display.drawPixel(4 + x[z], 1 + 13, WHITE); // horn left
          display.drawPixel(6 + x[z], 1 + 13, WHITE); // horn right
          display.drawPixel(3 + x[z], 1 + 13, WHITE); // horn left
          display.drawPixel(7 + x[z], 1 + 13, WHITE); // horn right
          display.drawPixel(1 + x[z], 4 + 13, WHITE); //finger left
          display.drawPixel(9 + x[z], 4 + 13, WHITE); //finger right
          display.drawPixel(1 + x[z], 3 + 13, WHITE); //arm left
          display.drawPixel(2 + x[z], 3 + 13, WHITE); //arm left
          display.drawPixel(3 + x[z], 3 + 13, WHITE); //arm left
          display.drawPixel(7 + x[z], 3 + 13, WHITE); //arm right
          display.drawPixel(8 + x[z], 3 + 13, WHITE); //arm right
          display.drawPixel(9 + x[z], 3 + 13, WHITE); //arm right
          display.fillRect(4 + x[z], 2 + 13, 3, 3, WHITE); //body
          display.drawPixel(3 + x[z], 5 + 13, WHITE); //leg left
          display.drawPixel(4 + x[z], 5 + 13, WHITE); //leg left
          display.drawPixel(3 + x[z], 6 + 13, WHITE); //leg left
          display.drawPixel(2 + x[z], 6 + 13, BLACK); //leg left
          display.drawPixel(6 + x[z], 5 + 13, WHITE); //leg right
          display.drawPixel(7 + x[z], 5 + 13, WHITE); //leg right
          display.drawPixel(8 + x[z], 6 + 13, WHITE); //leg right
          display.drawPixel(9 + x[z], 6 + 13, BLACK); //leg right
          display.drawPixel(4 + x[z], 3 + 13, BLACK); //eye left
          display.drawPixel(6 + x[z], 3 + 13, BLACK); //eye right
        }
        display.display();
      }// end drawing loop down





      // draw and move spaceship
      if (spacei == 0) {
        spacex = spacex + 4;
      }
      if (spacei == 1) {
        spacex = spacex - 4;
      }
      if (spacex >= spacerightbound) {  // random spaceshipmovement
        spacei = 1;
        spaceleftbound = random(10, 64);
      }
      if (spacex <= spaceleftbound) {
        spacei = 0;
        spacerightbound = random(65, 120);
      }
      display.fillRect(0 + spacex, 52, 14, 12, BLACK); //clear screen
      display.fillRect(6 + spacex, 58, 2, 2, WHITE); //body
      display.fillRect(5 + spacex, 60, 4, 2, WHITE); //body
      display.fillRect(4 + spacex, 62, 6, 2, WHITE); //body



      if (start == 1014) { // counter set back alien movmente
        start = 1000;

      }


      // falling stars

      for (int z = 0; z < 20; z++) {
        starsy[z] = starsy[z] + 2;
        display.drawPixel(starsx[z], starsy[z] - 2, BLACK);
        display.drawPixel(starsx[z], starsy[z], WHITE);
        if (starsy[z] == 64) { // if the star reach the ground 64 pixel it beginns from the top and rnd new x position
          starsy[z] = 12;
          starsx[z] = random(128);
        }
      }

      // falling alien


      if (start == random(1000, 1030) and fallingalieny == 10) { // only start if no Alien ship is on the way...
        display.fillRect(0 + fallingalienx, fallingalieny + 12, 14, 14, BLACK);// clear the last falling alien
        fallingalienx = random(10, 120);
        fallingalien = 1;
      }
      if (fallingalien == 1) {
        fallingalienx = fallingalienx + random(-2, 2); // nice x-movement(leftright) of the falling alien
        fallingalieny = fallingalieny + 1;
        display.fillRect(0 + fallingalienx, fallingalieny + 12, 14, 14, BLACK); //clear screen
        display.drawPixel(4 + fallingalienx, 1 + fallingalieny + 13, WHITE); // horn left
        display.drawPixel(6 + fallingalienx, 1 + fallingalieny + 13, WHITE); // horn right
        display.drawPixel(1 + fallingalienx, 2 + fallingalieny + 13, WHITE); //finger left
        display.drawPixel(9 + fallingalienx, 2 + fallingalieny + 13, WHITE); //finger right
        display.drawPixel(1 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm left
        display.drawPixel(2 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm left
        display.drawPixel(3 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm left
        display.drawPixel(7 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm right
        display.drawPixel(8 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm right
        display.drawPixel(9 + fallingalienx, 3 + fallingalieny + 13, WHITE); //arm right
        display.fillRect(4 + fallingalienx, 2 + fallingalieny + 13, 3, 3, WHITE); //body
        display.drawPixel(3 + fallingalienx, 5 + fallingalieny + 13, WHITE); //leg left
        display.drawPixel(4 + fallingalienx, 5 + fallingalieny + 13, WHITE); //leg left
        display.drawPixel(3 + fallingalienx, 6 + fallingalieny + 13, WHITE); //leg left
        display.drawPixel(2 + fallingalienx, 6 + fallingalieny + 13, WHITE); //leg left
        display.drawPixel(6 + fallingalienx, 5 + fallingalieny + 13, WHITE); //leg right
        display.drawPixel(7 + fallingalienx, 5 + fallingalieny + 13, WHITE); //leg right
        display.drawPixel(8 + fallingalienx, 6 + fallingalieny + 13, WHITE); //leg right
        display.drawPixel(9 + fallingalienx, 6 + fallingalieny + 13, WHITE); //leg right
        display.drawPixel(4 + fallingalienx, 3 + fallingalieny + 13, BLACK); //eye left
        display.drawPixel(6 + fallingalienx, 3 + fallingalieny + 13, BLACK); //eye right






        if (fallingalieny == 60) {  // if the alien touchs the ground


          fallingalieny = 10;
          fallingalien = 0;

        }

      } // end falling alien

      //shooting
      if (start == random(1000, 1030)) {
        display.fillCircle(shootx, shooty, 6, BLACK);
        shootx = spacex  + 5; // generate shoot between the horns
        shoot = 1;
      }

      if (shoot == 1) {
        shooty = shooty - 3;

        display.drawPixel(shootx, shooty + 1, BLACK);
        display.drawPixel(shootx, shooty + 2, BLACK);
        display.drawPixel(shootx, shooty + 3, BLACK);
        display.drawPixel(shootx, shooty, WHITE);
        display.drawPixel(shootx, shooty - 1, WHITE);
        display.drawPixel(shootx, shooty - 2, WHITE);
      }
      if (shooty <= 13) {  // set shooter back if the blast reach the upper end
        shoot = 0;
        shooty = 56;
        count = count + 10;
        display.fillRect(0, 0, 128, 12, BLACK); // kill upper artefacts
      }
      // collision spaceship and falling alien
      int proximityx = (spacex - fallingalienx); // easy accses to the precalculated variables
      int proximityy = (52 - fallingalieny);
      if  ((proximityx <= 5) and (proximityx >= -5) and (proximityy <= 5) and (proximityy >= -5)) {
        collision++;
        fallingalien = 0;
        fallingalieny = 10;
      }


      // fake header

      display.setTextSize(0);
      display.setCursor(20, 0);
      display.println(count);
      display.setCursor(100, 0);
      display.println(Level + gamenumber);

      // spaceship 1 2 3
      if (collision == 0)
      {
        display.fillRect(62, 0, 2, 2, WHITE); //body
        display.fillRect(61 , 2, 4, 2, WHITE); //body
        display.fillRect(60, 4, 6, 2, WHITE); //body
        display.fillRect(72, 0, 2, 2, WHITE); //body
        display.fillRect(71 , 2, 4, 2, WHITE); //body
        display.fillRect(70, 4, 6, 2, WHITE); //body
        display.fillRect(82, 0, 2, 2, WHITE); //body
        display.fillRect(81 , 2, 4, 2, WHITE); //body
        display.fillRect(80, 4, 6, 2, WHITE); //body
      }

      if (collision == 1)
      {
        display.fillRect(62, 0, 2, 2, WHITE); //body
        display.fillRect(61 , 2, 4, 2, WHITE); //body
        display.fillRect(60, 4, 6, 2, WHITE); //body
        display.fillRect(72, 0, 2, 2, WHITE); //body
        display.fillRect(71 , 2, 4, 2, WHITE); //body
        display.fillRect(70, 4, 6, 2, WHITE); //body
        display.fillRect(82, 0, 2, 2, BLACK); //body
        display.fillRect(81 , 2, 4, 2, BLACK); //body
        display.fillRect(80, 4, 6, 2, BLACK); //body
      }
      if (collision == 2)
      {
        display.fillRect(62, 0, 2, 2, WHITE); //body
        display.fillRect(61 , 2, 4, 2, WHITE); //body
        display.fillRect(60, 4, 6, 2, WHITE); //body
        display.fillRect(72, 0, 2, 2, BLACK); //body
        display.fillRect(71 , 2, 4, 2, BLACK); //body
        display.fillRect(70, 4, 6, 2, BLACK); //body
        display.fillRect(82, 0, 2, 2, BLACK); //body
        display.fillRect(81 , 2, 4, 2, BLACK); //body
        display.fillRect(80, 4, 6, 2, BLACK); //body
      }
      if (collision == 3)
      {
        display.fillRect(62, 0, 2, 2, BLACK); //body
        display.fillRect(61 , 2, 4, 2, BLACK); //body
        display.fillRect(60, 4, 6, 2, BLACK); //body
        display.fillRect(72, 0, 2, 2, BLACK); //body
        display.fillRect(71 , 2, 4, 2, BLACK); //body
        display.fillRect(70, 4, 6, 2, BLACK); //body
        display.fillRect(82, 0, 2, 2, BLACK); //body
        display.fillRect(81 , 2, 4, 2, BLACK); //body
        display.fillRect(80, 4, 6, 2, BLACK); //body
      }
      if (collision == 4) // gameover and Highscoredisplay

      {
        display.setTextSize(2);
        display.setTextColor(WHITE);
        display.setCursor(12, 30);
        display.println("GAME OVER");
        display.display();
        delay(5500);
        collision = 0;
        fallingalien = 0;
        fallingalieny = 10;
        display.clearDisplay();
        display.setTextSize(0);
        display.setCursor(0, 0);

        display.println("  /// HIGHSCORE ///");   // display Highscores
        Level = Level + 1;
        for (int z = 1; z < Level; z++) { // display the whole table, row after row
          display.setCursor(5, 11 * z );
          display.println("Game#:");
          display.setCursor(45, 11 * z );
          display.println(z + gamenumber);
          display.setCursor(90, 11 * z );
          Highscore[Level - 1] = count;
          display.println(Highscore[z]);
        }

        if (Level == 6) {
          Level = 1;

          gamenumber = gamenumber + 5; // increase the displayd highscore gamenumber after 5 Levels
        }

        count = 0; // reset the point counter
      
        display.display();
        delay(15000);
        display.clearDisplay();
      } // end gameover and Highscoredisplay

    }// End gamesequence
  } // loop end
}
