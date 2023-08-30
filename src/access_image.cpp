#include "image.h"

// HW0 #1
// const Image& im: input image
// int x,y: pixel coordinates
// int ch: channel of interest
// returns the 0-based location of the pixel value in the data array
int pixel_address(const Image& im, int x, int y, int ch)
  {
  // TODO: calculate and return the index
  return x+im.w*y+im.w*im.h*ch;
  // NOT_IMPLEMENTED();
  
  
  return 0;
  }

// HW0 #1
// const Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
// returns the value of the clamped pixel at channel ch
float get_clamped_pixel(const Image& im, int x, int y, int ch)
  {
  // TODO: clamp the coordinates and return the correct pixel value
  
  // NOT_IMPLEMENTED();
  x = (((x >= im.w) ? im.w-1 : x) < 0) ? 0 : ((x >= im.w) ? im.w-1 : x);
  y = (((y >= im.h) ? im.h-1 : y) < 0) ? 0 : ((y >= im.h) ? im.h-1 : y);
  
  return im.data[pixel_address(im, x, y, ch)];
  }


// HW0 #1
// Image& im: input image
// int x,y,ch: pixel coordinates and channel of interest
void set_pixel(Image& im, int x, int y, int c, float value)
  {
  // TODO: Only set the pixel to the value if it's inside the image
  
    // NOT_IMPLEMENTED();
    if(x < im.w && y < im.h && c < im.c) {
      im.data[pixel_address(im, x, y, c)] = value;
    } else {
      return;
    }
  }



// HW0 #2
// Copies an image
// Image& to: destination image
// const Image& from: source image
void copy_image(Image& to, const Image& from)
  {
  // allocating data for the new image
  to.data=(float*)calloc(from.w*from.h*from.c,sizeof(float));
  to.c=from.c;
  
  // TODO: populate the remaining fields in 'to' and copy the data
  // You might want to check how 'memcpy' function works
  
  // NOT_IMPLEMENTED();
  to.w = from.w;
  to.h = from.h;
  memcpy(to.data, from.data, sizeof(float)*from.w*from.h*from.c);
  
  }
