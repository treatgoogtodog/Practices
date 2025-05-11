#include <stdio.h>
#include <iostream>

using namespace std;

struct image{
    int* pix;
    unsigned int width;
    unsigned int height;
};

void printImage(const image& img){
    for(int i = 0; i < img.height; i++){
        for (int j = 0; j < img.width; j++)
        {
           cout << img.pix[i * img.width + j];
           printf(" ");
        }
        printf("\n");
    }
}

image halve(const image& img){
    int* pixiv = new int[(img.height / 2) * (img.width / 2)];
    unsigned int newwidth = img.width/2+1;
    unsigned int newheight = img.height/2+1;

    image GoglImg = {pixiv, newwidth, newheight};

    for (int i = 0; i < GoglImg.height; i++) {
        for (int j = 0; j < GoglImg.width; j++) {
            GoglImg.pix[i * GoglImg.width + j] = img.pix[(i * 2) * img.width + (j * 2)];
        }
    }

    return GoglImg;
}

int main(){
    int pix[] = {1, 3, 0, 5, 2,
                 4, 1, 8, 3, 1,
                 3, 3, 1, 3, 2};
    
    image img = {pix, 5, 3};
    printImage(img);
    printImage(halve(img));

    return 0;
}