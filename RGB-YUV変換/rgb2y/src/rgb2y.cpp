/* �J���[�摜(RGB)���甒����(Y���o)�v���O���� rgb2y.cpp */
//#include<stdio.h>
//#include<stdlib.h>
#include"mypgpm.h"

void make_y_image( )
/* ���摜 image1_ppm ����Y���o���� image2 �ɑ������ */
{
    int x, y;    /* ����ϐ� */

    printf("�����摜���쐬���܂��D\n");
    x_size2 = x_size1;  /* ����f�� */
    y_size2 = y_size1;  /* �c��f�� */
    for ( y = 0; y < y_size2; y ++ ){
//	       �Q�Q�Q�Q�Q�Q�Q�Q�Q�Q			
        for ( /*	a	 */ ){
//	      �P�P�P�P�P�P�P�P�P�P			
            image2[y][x] = (unsigned char)	//�ϊ���
//	 			 �Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q�Q
				/*		  b		   */
//				�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P�P
        }
    }
}

int main( )
{
    load_image_data_ppm(); /* �摜�f�[�^�� image1_ppm �ɓǂݍ��� */
	make_y_image();        /* image1_ppm ��Y�ϊ��� image2 �� */
    save_image_data();     /* image2 ��ۑ����� */
    return 0;
}