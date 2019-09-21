#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<string>

using namespace std;
using namespace cv;

void neg(string nome);

int main(){
	clock_t tempo = clock();
	string imgs[1] = {"im3.jpg"};
	int tam = sizeof(imgs)/sizeof(imgs[0]);
    for(int f=0;f<tam;f++){
    	neg(imgs[f]);
    }

    cout<<"tempo de processamento:"<<(double)(clock() - tempo)/CLOCKS_PER_SEC<<endl;
    return 0;
}

void neg(string nome) {
	Mat imagem;

    imagem = imread(nome,IMREAD_COLOR);		//Le a imagem de entrada e converte ela para uma matriz de 3 canais (BGR)

    if(!imagem.data){
        cout<<"Aconteceu erros com a leitura da imagem!"<<endl;
    }


    for(int i = 0; i<(imagem.channels()); i++){
        for(int j=0; j<(imagem.rows)/16; j++){
            for(int k =0; k<(imagem.cols)/16; k++){
                imagem.at<Vec3b>(j,k)[i] = 255 - imagem.at<Vec3b>(j,k)[i];
        }
    }
}

    namedWindow("Janela",WINDOW_NORMAL);
    imwrite("teste3.jpg",imagem);
    //imshow("Janela",imagem);
    //waitKey(300);

    //cout<<"tempo de processamento:"<<(double)(clock() - tempo)/CLOCKS_PER_SEC<<endl;
    //return 0;
}


