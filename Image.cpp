#include <stdio.h>
#include <iostream>

using namespace std;

struct Image{
    int* pixels;
    unsigned int width;
    unsigned int height;
};

void printImage(const Image& img){
    for(int i = 0; i < img.height; i++){
        for (int j = 0; j < img.width; j++)
        {
           cout << img.pixels[i * img.width + j];
           printf(" ");
        }
        printf("\n");
    }
}

Image halve(const Image& img){
    int* pixiv = new int[(img.height / 2) * (img.width / 2)];
    unsigned int newwidth = img.width/2+1;
    unsigned int newheight = img.height/2+1;

    Image GoglImg = {pixiv, newwidth, newheight};

    for (int i = 0; i < GoglImg.height; i++) {
        for (int j = 0; j < GoglImg.width; j++) {
            GoglImg.pixels[i * GoglImg.width + j] = img.pixels[(i * 2) * img.width + (j * 2)];
        }
    }

    return GoglImg;
}

int main(){
    int pixels[] = {1, 3, 0, 5, 2,
                 4, 1, 8, 3, 1,
                 3, 3, 1, 3, 2};
    
    Image img = {pixels, 5, 3};
    printImage(img);
    printImage(halve(img));

    return 0;
}