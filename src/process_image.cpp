#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>

#include "image.h"

using namespace std;

// HW0 #3
// const Image& im: input image
// return the corresponding grayscale image
Image rgb_to_grayscale(const Image& im)
  {
  assert(im.c == 3); // only accept RGB images
  Image gray(im.w,im.h,1); // create a new grayscale image (note: 1 channel)
  
  // TODO: calculate the pixels of 'gray'
  
  
  // NOT_IMPLEMENTED();
  const float r_const = 0.299;
  const float g_const = 0.587;
  const float b_const = 0.114;
  float change_val = 0.0f;
  for(int i = 0; i < im.w; i++) {
    for(int j = 0; j < im.h; j++) {
      change_val = r_const * im(i, j, 0) + g_const* im(i, j, 1) + b_const * im(i, j, 2);
      gray(i, j, 0) = change_val;
    }
  }
  
  return gray;
  }



// Example function that changes the color of a grayscale image
Image grayscale_to_rgb(const Image& im, float r, float g, float b)
  {
  assert(im.c == 1);
  Image rgb(im.w,im.h,3);
  
  for(int q2=0;q2<im.h;q2++)for(int q1=0;q1<im.w;q1++)
    {
    rgb(q1,q2,0)=r*im(q1,q2);
    rgb(q1,q2,1)=g*im(q1,q2);
    rgb(q1,q2,2)=b*im(q1,q2);
    }
  
  return rgb;
  }




// HW0 #4
// Image& im: input image to be modified in-place
// int c: which channel to shift
// float v: how much to shift
void shift_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: shift all the pixels at the specified channel
  
  // NOT_IMPLEMENTED();
  float pix = 0.0f;
  for(int i = 0; i < im.w; i++) {
    for (int j = 0; j < im.h; j++) {
      pix = 0.0f;
      pix = im(i, j, c);
      pix += v;
      im.set_pixel(i, j, c, pix);
    }
  }
  
  }

// HW0 #8
// Image& im: input image to be modified in-place
// int c: which channel to scale
// float v: how much to scale
void scale_image(Image& im, int c, float v)
  {
  assert(c>=0 && c<im.c); // needs to be a valid channel
  
  // TODO: scale all the pixels at the specified channel
  
  NOT_IMPLEMENTED();
  
  }


// HW0 #5
// Image& im: input image to be modified in-place
void clamp_image(Image& im)
  {
  // TODO: clamp all the pixels in all channel to be between 0 and 1
  
  // NOT_IMPLEMENTED();
  for(int i = 0; i < im.w; i++) {
    for(int j = 0; j < im.h; j++) {
      im.set_pixel(i, j, 0, (im(i, j, 0) < 0 ? 0 : im(i, j, 0)) > 1.0 ? 1.0 : im(i, j, 0) < 0 ? 0 : im(i, j, 0));
      im.set_pixel(i, j, 1, (im(i, j, 1) < 0 ? 0 : im(i, j, 1)) > 1.0 ? 1.0 : im(i, j, 1) < 0 ? 0 : im(i, j, 1));
      im.set_pixel(i, j, 2, (im(i, j, 2) < 0 ? 0 : im(i, j, 2)) > 1.0 ? 1.0 : im(i, j, 2) < 0 ? 0 : im(i, j, 2));
    }
  }
  
  }

// These might be handy
float max(float a, float b, float c)
  {
  return max({a,b,c});
  }

float min(float a, float b, float c)
  {
  return min({a,b,c});
  }


// HW0 #6
// Image& im: input image to be modified in-place
void rgb_to_hsv(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to HSV format
  
  NOT_IMPLEMENTED();
  
  for(int i = 0; i < im.w; i++) {
    for(int j = 0; j < im.h; j++) {
      float r = 0.0f;
      float g = 0.0f;
      float b = 0.0f;
      float v = 0.0f;
      float m = 0.0f;
      float c = 0.0f;
      float s = 0.0f;
      float h = 0.0f;
      r = im(i, j, 0);
      g = im(i, j, 1);
      b = im(i, j, 2);
      if(r > g) {
        v = r;
      } else {
        v = g;
      }
      if(v < b) {
        v = b;
      }
      if(r < g) {
        m = r;
      } else {
        m = g;
      }
      if(m > b) {
        m = b;
      }
      c = v-m;
      s = (v == 0) ? 0 : c/v;
      if(c == 0) {
        h == 0;
      } else if(v == r) {
        h =   (g-b) / c;
      } else if (v == g) {
        h = (b-r) / c + 2;
      } else if (v == b) {
        h = (r-g) / c + 4;
      }
      if(h < 0) {
        h = h/6 + 1;
      } else {
        h = h/6;
      }
      im(i, j, 0) = h;
      im(i, j, 1) = s;
      im(i, j, 2) = v;
    }
  }
  
  }

// HW0 #7
// Image& im: input image to be modified in-place
void hsv_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from HSV format to RGB format
  
  // NOT_IMPLEMENTED();
  for(int i = 0; i < im.w; i++) {
    for(int j = 0; j < im.h; j++) {
      
      float h = im(i, j, 0);
      float s = im(i, j, 1);
      float v = im(i, j, 2);
      float c = v * s;
      
      float x = c * (1 - fabs((fmod(6 *h, 2) - 1)));
      float m =   v - c;
      float r = 0.0f;
      float g = 0.0f;
      float b = 0.0f;
      if(h >= 0.0f && h < 1.0f/6.0f) {
        r = c;
        g = x;
      } else if (h >= 1.0f/6.0f && h < 2.0f/6.0f) {
        r = x;
        g = c;
      } else if (h >= 2.0f/6.0f && h < 3.0f/6.0f) {
        g = c;
        b = x;
      } else if (h >= 3.0f/6.0f && h < 4.0f/6.0f) {
        g = x;
        b = c;
      } else if (h >= 4.0f/6.0f && h < 5.0f/6.0f) {
        r = x;
        b = c;
      } else if (h >= 5.0f/6.0f && h < 1.0f) {
        r = c;
        b = x;
      } 
      r += m;
      g += m;
      b += m;
      im(i, j, 0) = r;
      im(i, j, 1) = g;
      im(i, j, 2) = b;
    }
  }
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void rgb_to_lch(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from RGB format to LCH format
  
  
  NOT_IMPLEMENTED();
  
  }

// HW0 #9
// Image& im: input image to be modified in-place
void lch_to_rgb(Image& im)
  {
  assert(im.c==3 && "only works for 3-channels images");
  
  // TODO: Convert all pixels from LCH format to RGB format
  
  NOT_IMPLEMENTED();
  
  }



// Implementation of member functions
void Image::clamp(void) { clamp_image(*this); }
void Image::shift(int c, float v) { shift_image(*this,c,v); }
void Image::scale(int c, float v) { scale_image(*this,c,v); }

void Image::HSVtoRGB(void) { hsv_to_rgb(*this); }
void Image::RGBtoHSV(void) { rgb_to_hsv(*this); }
void Image::LCHtoRGB(void) { lch_to_rgb(*this); }
void Image::RGBtoLCH(void) { rgb_to_lch(*this); }
