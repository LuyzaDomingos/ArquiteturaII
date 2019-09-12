#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<omp.h>

using namespace std;
using namespace cv;

int main(){

    Mat imagem;

    imagem = imread("astro.jpg",IMREAD_COLOR);

    if(!imagem.data){
        cout<<"Aconteceu erros com a leitura da imagem!"<<endl;
    }
    clock_t tempo = clock();


    for(int i = 0; i<imagem.rows; i++)
        for(int j=0; j<imagem.cols; j++)
            imagem.at<Vec3b>(i,j)[0] = 255 - imagem.at<Vec3b>(i,j)[0];
            
     for(int i = 0; i<imagem.rows; i++)
        for(int j=0; j<imagem.cols; j++)
        imagem.at<Vec3b>(i,j)[1] = 255 - imagem.at<Vec3b>(i,j)[1];
        
    
     for(int i = 0; i<imagem.rows; i++)
        for(int j=0; j<imagem.cols; j++)
            imagem.at<Vec3b>(i,j)[2] = 255 - imagem.at<Vec3b>(i,j)[2];
        
        
    cout<<"tempo de processamento:"<<(double)(clock() - tempo)/CLOCKS_PER_SEC<<endl;


    namedWindow("Janela",WINDOW_NORMAL);
    imshow("Janela",imagem);
    waitKey();

    return 0;
}


