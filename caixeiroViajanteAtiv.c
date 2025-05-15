#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define V 5
#define qAresta 20
#define nullAresta 0
#define qtdComb 24

// como representar em lista de arestas?
struct Aresta{
	int vEmergente;
	int vIncidente;
	float peso;
}aresta[qAresta];

struct Caixeiro{
	int combinacao[V+1];
	float custo;
}combCaxViaj[qtdComb];

int posCx = 0;




struct Caminho{
	char texto[8*V];
}caminho[V];

float vetorCusto[V];

int mAdj[V][V];

//funções
void inicializar();
void inicializarAresta();
void imprimirListaAresta();
void imprimirMatriz();
void transformarArestaEmMatriz();
void transformarMatrizEmAresta();
void imprimirVetorCusto();
void imprimirCaminhos();
void caixeiro(int vInicio);
void imprimirCaixeiro();
void buscarMenorRota();
void calcularPesos();
void combinacoes(
							);


void main(void){	

	inicializar();
	imprimirMatriz();
	transformarMatrizEmAresta();
	imprimirListaAresta();
	caixeiro(3);
	imprimirCaixeiro();
	buscarMenorRota();	   

}

// criar a função de inicialização
void inicializar(){
	setlocale(LC_ALL,"Portuguese");
	
	int i, j;
	for(i = 0; i < V; i++)
		vetorCusto[i] = 8015056586684760100;

	for(i = 0; i < V;i++)
		for(j = 0; j < V;j++)
			mAdj[i][j] = nullAresta;
			
	//vertice 0
	mAdj[0][1] = 2; 
	mAdj[0][2] = 1;
	mAdj[0][3] = 12;
	mAdj[0][4] = 3;
		
	//vertice 1
	mAdj[1][0] = 2;
	mAdj[1][2] = 3; 
	mAdj[1][3] = 6;
	mAdj[1][4] = 4; 
		
	//vertice 2
	mAdj[2][0] = 1;
	mAdj[2][1] = 3;
	mAdj[2][3] = 1;
	mAdj[2][4] = 5;  
	
	//vertice 3
	mAdj[3][0] = 12;
	mAdj[3][1] = 6;
	mAdj[3][2] = 1;
	mAdj[3][4] = 15;
	
	//vertice 4
	mAdj[4][0] = 3;
	mAdj[4][1] = 4; 
	mAdj[4][2] = 5;
	mAdj[4][3] = 15;
	
}

// criar a função de impressão da matriz
void imprimirMatriz(){
	int i,j;
	for(i=0;i<30;i++) printf("=");
	printf("\n           Matriz          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i=0;i < V;i++){
		for(j=0;j< V;j++){
			printf("%d\t",mAdj[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void imprimirListaAresta(){
	int i;
	for(i=0;i<30;i++) printf("=");
	printf("\n     Lista de aresta          \n");
	for(i=0;i<30;i++) printf("-");
	printf("\n");
	for(i = 0; i < qAresta; i++){
		printf("\t%d  ==>  %d\t%.f\n",aresta[i].vEmergente,aresta[i].vIncidente,aresta[i].peso);
	}
	for(i=0;i<30;i++) printf("=");
	printf("\n");
}

void transformarMatrizEmAresta(){
	// a partir da matriz de incidencia gera-se a lista de aresta
	int i, j, k = 0;
	for(i = 0; i < V;i++){
		for(j = 0; j < V;j++){
			if(mAdj[i][j] != nullAresta){
				aresta[k].vEmergente = i;
				aresta[k].vIncidente = j;
				aresta[k].peso = mAdj[i][j];
				k++;
			}
		}
	}
}

void imprimirVetorCusto(){
	int i;
	printf("\n\n--------- Vetor Custos --------\n");
	for(i = 0; i < V;i++){
		printf("%.f\n",vetorCusto[i]);
	}
	printf("\n\n--------------------------\n");
}

void imprimirCaminhos(){
	int i, j;
	printf("\n\n--------------- Vetor Caminhos com Custo ------------------\n");
	for(i=0;i < V;i++){
		printf("Custo = %.f\t%s\n",vetorCusto[i],caminho[i].texto);
	}
	printf("\n--------------------------------------------------------\n");
}

void caixeiro(int vInicio){

	//criar um vetor com os vertices diferentes de vInicio
	
	//criar um vetor auxiliar temporário para armazenar as combinações
    // e criar outro vetor para marcar os números já utilizados


    // cria todas as combinações do vetor com números distintos e armazenar
    // na estrutura Caixeiro a partir da função
    combinacoes();
    
    // Na estrutura do caixeiro não esqueça de adicionar
	// o primeiro e ultimo elemento que é vInicio ex: vInicio = 1
	// combCaxViaj[10] = 1 0 2 3 4 1
	
	//Após criar todas as combinações chamar a função calcular
	// os pesos dos caminhos gerados	
	calcularPesos(); 
	
}

void combinacoes() {
   
}

void calcularPesos(){
	
}

void buscarMenorRota(){
	int i, posicao;

	// criar a busca do menor valor, isto é, percorrer o vetor
	// em busca do menor igual em ED1

	printf("\n\nA menor Rota é : ");
	for(i = 0; i < V+1; i++){
		printf("%d ", combCaxViaj[posicao].combinacao[i]);
	}
	printf("  com custo: %0.f\n",combCaxViaj[posicao].custo);
}

void imprimirCaixeiro(){
	printf("\n\n======================= Caixeiro Viajante =========================\n");
	int i, j, k;
	for(i = 0; i < qtdComb; i++){
		for(j = 0; j < V; j++){
			printf("%d ",combCaxViaj[i].combinacao[j]);
		}
		printf("%d\t%0.f\n",combCaxViaj[i].combinacao[j],
		combCaxViaj[i].custo);		
	}
	printf("\n\n===================================================================\n");
}




