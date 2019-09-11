#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main(){

    Mat imagem;

    imagem = imread("arara.jpg",IMREAD_COLOR);

    if(!imagem.data){
        cout<<"Aconteceu erros com a leitura da imagem!"<<endl;
    }
    clock_t tempo = clock();

    for(int i = 0; i<imagem.rows; i++){
        for(int j=0; j<imagem.cols; j++){
            for(int k =0; k<imagem.channels(); k++){

                imagem.at<Vec3b>(i,j)[k] = 255 - imagem.at<Vec3b>(i,j)[k];
            }
        }
    }

    printf("tempo de processamento: %.2f\n", (double)(clock() - tempo)/CLOCKS_PER_SEC);

    namedWindow("Janela",WINDOW_NORMAL);
    imshow("Janela",imagem);
    waitKey();

    return 0;
}


