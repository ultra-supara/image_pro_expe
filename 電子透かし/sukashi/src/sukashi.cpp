/*電子透かしのプログラム sukashi.cpp*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mypgpm.h"
#include "FFT.h"

#define RATIO 100; /*混入させる画像に掛ける係数(=ε)*/

double data2[FFT_MAX][FFT_MAX];
double jdata2[FFT_MAX][FFT_MAX];

void make_data() /*image1[y][x]のデータをdata[y][x],jdata[y][x]に代入する*/
{
  int i, j;
  num_of_data = x_size1;
  for (i = 0; i < num_of_data; i++)
  {
    for (j = 0; j < num_of_data; j++)
    {
      data[i][j] = (double)image1[i][j];
      jdata[i][j] = 0.0;
    }
  }
}

void make_output_image() /*データdata[y][x],jdata[y][x]をimage2[y][x]になおす（処理後データのクリッピング）*/
{
  int x, y;
  x_size2 = num_of_data;
  y_size2 = num_of_data;
  for (x = 0; x < x_size2; x++)
  {
    for (y = 0; y < y_size2; y++)
    {
      if (data[y][x] < 0.0)
        image2[y][x] = 0;
      else if (data[y][x] > 255)
        image2[y][x] = 255;
      else
        image2[y][x] = (unsigned char)data[y][x];
    }
  }
}

void copy_image_data() /*image1[y][x]==>image2[y][x]へデータをコピー（処理前のデータコピー）*/
{
  int i, j;
  for (i = 0; i < y_size1; i++)
  {
    for (j = 0; j < x_size1; j++)
    {
      image2[i][j] = image1[i][j];
    }
  }
  y_size2 = y_size1;
  x_size2 = x_size1;
}

void copy_FFT_data() /*data,jdata==>data2,jdata2のデータのコピー（処理前の複素化したデータのコピー）*/
{
  int i, j;
  for (i = 0; i < num_of_data; i++)
  {
    for (j = 0; j < num_of_data; j++)
    {
      data2[j][i] = data[j][i];
      jdata2[j][i] = jdata[j][i];
    }
  }
}

void coding() /*原画像と混入する画像を指定して透かし入りの画像を保存する*/
{
  int i, j;
  printf("\n混入する画像を読み込みます\n");
  load_image_data();
  copy_image_data();
  printf("\n原画像を読み込みます\n");
  load_image_data();
  make_data();
  FFT2(1);
  for (i = 0; i < y_size1; i++)
  {
    for (j = 0; j < x_size1; j++)
    {
      data[i][j] = data[i][j] + image2[i][j] * RATIO;
    }
  }
  FFT2(-1); /*2次元　逆FFTの実行*/
  make_output_image();
  printf("\n電子透かし入りの画像を保存します\n");
  save_image_data();
}

void decoding()
/*透かし入りの画像と原画像を指定して抽出された画像を保存する*/
{
  int i, j;
  double d;
  printf("\n原画像を読み込みます\n");
  load_image_data();
  make_data();
  FFT2(1);
  copy_FFT_data();
  printf("\n透かし入りの画像を読み込みます\n");
  load_image_data();
  make_data();
  FFT2(1);
  x_size2 = x_size1;
  y_size2 = y_size1;
  for (i = 0; i < y_size2; i++)
  {
    for (j = 0; j < x_size2; j++)
    {
      d = (data[i][j] - data2[i][j]) / RATIO;
      if (d < 0.0)
        image2[i][j] = 0;
      else if (d > MAX_BRIGHTNESS)
          image2[i][j] = MAX_BRIGHTNESS;
      else image2[i][j] = (unsigned char)d;
    }
  }
  printf("\n抽出された画像を保存します\n");
  save_image_data();
}

int main()
{
  int mode;
  printf("***電子透かしのプログラム***\n");
  do
  {
    printf("透かしを入れる(1)/透かしを取る(-1)");
    scanf("%d", &mode);
  } while (mode != 1 && mode != -1);
  if (mode == 1)
    coding();
  else
    decoding();
  return 0;
}
