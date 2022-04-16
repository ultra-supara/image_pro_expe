/* ƒJƒ‰[‰æ‘œ(RGB)‚©‚ç”’•‰»(Y’Šo)ƒvƒƒOƒ‰ƒ€ rgb2y.cpp */
//#include<stdio.h>
//#include<stdlib.h>
#include"mypgpm.h"

void make_y_image( )
/* Œ´‰æ‘œ image1_ppm ‚©‚çY’Šo‚µ‚Ä image2 ‚É‘ã“ü‚·‚é */
{
    int x, y;    /* §Œä•Ï” */

    printf("”’•‰æ‘œ‚ğì¬‚µ‚Ü‚·D\n");
    x_size2 = x_size1;  /* ‰¡‰æ‘f” */
    y_size2 = y_size1;  /* c‰æ‘f” */
    for ( y = 0; y < y_size2; y ++ ){
//	       QQQQQQQQQQ			
        for ( /*	a	 */ ){
//	      PPPPPPPPPP			
            image2[y][x] = (unsigned char)	//•ÏŠ·®
//	 			 QQQQQQQQQQQQQQQQQQ
				/*		  b		   */
//				PPPPPPPPPPPPPPPPPP
        }
    }
}

int main( )
{
    load_image_data_ppm(); /* ‰æ‘œƒf[ƒ^‚ğ image1_ppm ‚É“Ç‚İ‚Ş */
	make_y_image();        /* image1_ppm ‚ğY•ÏŠ·‚µ image2 ‚Ö */
    save_image_data();     /* image2 ‚ğ•Û‘¶‚·‚é */
    return 0;
}