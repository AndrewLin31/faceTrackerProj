#include<Servo.h>

Servo x, y;

const int width = 640, height = 480;  // total resolution of the video
float xpos = 90, ypos = 0;  // initial positions of both Servos
void setup() {
  
  /* BAUD RATE */
  Serial.begin(9600);
  
  /* Servo Pins */
  x.attach(2); // Left Right
  y.attach(3); // Up Down

  /* Initial Camera Position */
  x.write(xpos);
  y.write(ypos);
}
const double angle = .5;   // degree of increment or decrement

void loop() {
  if (Serial.available() > 0)
  {
    int x_mid, y_mid;
    
    if (Serial.read() == 'X')
    {
      x_mid = Serial.parseInt();  // read center x-coordinate
      if (Serial.read() == 'Y')
      y_mid = Serial.parseInt(); // read center y-coordinate
    }
    
    /* Makes x_mid and y_mid fit into width and height of middle square */
    if (x_mid > width / 2 + 30)
      xpos += angle;
    if (x_mid < width / 2 - 30)
      xpos -= angle;
    if (y_mid < height / 2 + 30)
      ypos += angle;
    if (y_mid > height / 2 - 30)
      ypos -= angle;

    /* Checks if servo is out of range */
    if (xpos >= 180)
      xpos = 180;
    else if (xpos <= 0)
      xpos = 0;
    if (ypos >= 180)
      ypos = 180;
    else if (ypos <= 0)
      ypos = 0;
    /* Alters Servo Positions */
    x.write(xpos);
    y.write(ypos);

  }
}
