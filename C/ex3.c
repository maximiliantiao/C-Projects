// Program that calculates area and perimeter of rectangle
// and calcultaes the area and circumference of circle
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PI 3.14159

void calcRectAreaPeri(int rectHeight, int rectWidth) {
  int rectArea = rectWidth * rectHeight;
  int rectPeri = (2 * rectWidth) + (2 * rectHeight);

  printf("Area of rectangle: %d\n", rectArea);
  printf("Perimter of rectangle: %d\n", rectPeri);

}

void calcCirAreaCircum(int cirRadius) {
  double cirArea = PI * pow(cirRadius, 2);
  double cirCircum = 2 * PI * cirRadius;

  printf("Area of circle: %lf\n", cirArea);
  printf("Circumference of circle: %lf\n", cirCircum);
}

int main() {
  // Get user input and calculate area and perimter of given dimensions of rectangle
  int height;
  printf("Enter height of rectangle: ");
  scanf("%d", &height);

  int width;
  printf("Enter width of rectangle: ");
  scanf("%d", &width);
  printf("\n");
  calcRectAreaPeri(width, height);
  printf("\n");

  // Get user input and claculate area and circumference of given radius of circle
  int radius;
  printf("Enter a circle radius: ");
  scanf("%d", &radius );
  calcCirAreaCircum(radius);
  printf("\n");

}
