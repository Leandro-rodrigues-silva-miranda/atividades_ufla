#include <iostream>
#include <fstream>
using namespace std;

struct registro{
	string nome;
	string tipo;
	int distancia;
	};
void intercala(registro pokemon[],int inicio, int meio, int fim){
	int i=inicio;
	int j=meio+1;
	int tamanho = fim-inicio+1;
	registro aux[tamanho];
	int k;
	for (k=0; k<tamanho; k++){
		if ((i<=meio) and (j<=fim)){
			if (pokemon[i].distancia <= pokemon[j].distancia){
				aux[k].distancia=pokemon[i].distancia;	
				aux[k].nome=pokemon[i].nome;	
				aux[k].tipo=pokemon[i].tipo;
				i++;
				}else{
					aux[k].distancia=pokemon[j].distancia;
					aux[k].nome=pokemon[j].nome;
					aux[k].tipo=pokemon[j].tipo;
					j++;
					}
			}else if ( i > meio){
				aux[k].distancia=pokemon[j].distancia;
				aux[k].nome=pokemon[j].nome;
				aux[k].tipo=pokemon[j].tipo;
				j++;
				}else{
					aux[k].distancia=pokemon[i].distancia;
					aux[k].nome=pokemon[i].nome;
					aux[k].tipo=pokemon[i].tipo;
					i++;
					}
		}
	for (k=0; k < tamanho; k++){
		pokemon[inicio+k].distancia=aux[k].distancia;
		pokemon[inicio+k].nome=aux[k].nome;
		pokemon[inicio+k].tipo=aux[k].tipo;
		}
	}
void mergesort(registro pokemon[],int inicio,int fim,int fimtot){
	int meio;
	if (inicio<fim){
		meio=(inicio+fim)/2;
		mergesort(pokemon,inicio,meio,fimtot);
		mergesort(pokemon,meio+1,fim,fimtot);
		intercala(pokemon,inicio,meio,fim);
		}
	}

int main(){
	int num;
	string tipodesejado;
	int qdddesejada;
	ifstream arquivo("dados.txt");
	arquivo >> num;
	registro pokemon[num];
	int i;
	for (i=0; i<num; i++){
		arquivo >> pokemon[i].nome;
		arquivo >> pokemon[i].tipo;
		arquivo >> pokemon[i].distancia;
		}
	cin >> tipodesejado;
	cin >> qdddesejada;
	for (i=0; i<num; i++){
		cout << pokemon[i].nome << " "
		<< pokemon[i].tipo << " "
		<< pokemon[i].distancia << endl;
		}
	cout <<endl;
	mergesort(pokemon,0,num-1,num);
	for (i=0; i<num; i++){
		cout << pokemon[i].nome << " "
		<< pokemon[i].tipo << " "
		<< pokemon[i].distancia << endl;
		}
	int k=0;
	ofstream arquivo_final("pokemon.txt");
	for (i=0; i<num; i++){
		if ((pokemon[i].tipo==tipodesejado) and (k<qdddesejada)){
			arquivo_final << pokemon[i].nome << endl;
			k++;
			}
		}
	return 0;
	}
