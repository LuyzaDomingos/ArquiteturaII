#include<iostream>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/core/core.hpp>
#include<string>

using namespace std;
using namespace cv;

void neg(string nome);

int main(){
	string imgs[4] = {"arara.jpg","astro.jpg","elsa.jpg","paisagem.jpg"};
    clock_t tempo = clock();
    for(int f=0;f<4;f++){
    	neg(imgs[f]);
    }
    
    cout<<"tempo de processamento:"<<(double)(clock() - tempo)/CLOCKS_PER_SEC<<endl;
    return 0;
}

void neg(string nome) {
	Mat imagem;

    imagem = imread(nome,IMREAD_COLOR);

    if(!imagem.data){
        cout<<"Aconteceu erros com a leitura da imagem!"<<endl;
    }
    

    for(int i = 0; i<imagem.channels(); i++)
        for(int j=0; j<imagem.rows; j++)
            for(int k =0; k<imagem.cols; k++)
                imagem.at<Vec3b>(j,k)[i] = 255 - imagem.at<Vec3b>(j,k)[i];
            

    namedWindow("Janela",WINDOW_NORMAL);
    imshow("Janela",imagem);
    waitKey(600);
}


