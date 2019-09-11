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


    //#pragma omp parallel default(none) shared(image)
    //{
        #pragma omp for
    for(int i = 0; i<imagem.rows; i++){
        for(int j=0; j<imagem.cols; j++){

        //Vec3b& bgr = imagem.at<Vec3b>(i,j);
        //bgr[0] = 255 - imagem.at<Vec3b>(i,j);
            imagem.at<Vec3b>(i,j)[0] = 255 - imagem.at<Vec3b>(i,j)[0];
        }
    }
    #pragma omp for
     for(int i = 0; i<imagem.rows; i++){
        for(int j=0; j<imagem.cols; j++){

        //Vec3b& bgr = imagem.at<Vec3b>(i,j);
        //bgr[1] = 255 - imagem.at<Vec3b>(i,j);
        imagem.at<Vec3b>(i,j)[1] = 255 - imagem.at<Vec3b>(i,j)[1];
        }
    }

    #pragma omp for
     for(int i = 0; i<imagem.rows; i++){
        for(int j=0; j<imagem.cols; j++){

        //Vec3b& bgr = imagem.at<Vec3b>(i,j);
        //bgr[2] = 255 - imagem.at<Vec3b>(i,j);
            imagem.at<Vec3b>(i,j)[2] = 255 - imagem.at<Vec3b>(i,j)[2];
        }
    }



//}




    printf("tempo de processamento: %.2fs\n", (double)(clock() - tempo)/CLOCKS_PER_SEC);

    namedWindow("Janela",WINDOW_NORMAL);
    imshow("Janela",imagem);
    waitKey();

    return 0;
}


