#include <stdio.h>
/*Resolução para a questão 2 do segundo capítulo do livro do Dieguez.
No código abaixo, faz-se a combinação de uma lista de N números
inteiros, tomados P a P. A entrada consiste dos valores de N e de P,
seguidos dos N inteiros a serem combinados. A idéia do algoritmo é
manipular um vetor com as posições dos elementos a serem exibidos e
imprimir a sequencia cada vez que esse vetor é alterado. Assim o
problema se resume a determinar como será manipulado esse vetor. Mais
explicações se encontram ao longo do código*/
//Rotina de impressão da combinação atual
void imp(int n,int p,int vet[n],int pos[p])
{
  int i,j;
  for(i=0;i<p;i++)
  {
    /*o i-ésimo elemento do vetor de posições armazena o índice do
    i-ésimo elemento do vetor de entrada ("vet")tomado na combinação
    atual.*/
    j=pos[i];
    printf("%d ",vet[j]);
  }
  printf("\n");
}
/*Aqui o vetor das posições dos itens escolhidos é manipulado. Esta é
a parte mais importante do programa!*/
void comb(int n,int p,int vet[n])
{
  int i,j;
  //Declaração do vetor de posições.
  int pos[p];
  /*Inicialmente, são selecionados os P primeiros números do vetor de
  entrada.*/
  for(i=0;i<p;i++) pos[i]=i;
  /*A condição de parada ocorre quando o primeiro elemento selecionado
  ocupa a última posição possível. Mais ou menos assim:
     Início                        1º passo                Final
    pos[0]->vet[0] (pos[0]=0)     pos[0]->vet[0]          vet[0]
    pos[1]->vet[1]                pos[1]->vet[1]          vet[1]
         ...                          ...                 ...
    pos[p-1]->vet[p-1]               vet[p-1]        pos[0]->vet[n-p]
       vet[p]                    pos[p-1]->vet[p]   pos[1]->vet[n-p+1]
         ...                          ...                  ...
       vet[n-1]                     vet[n-1]        pos[p-1]->vet[n-1]*/
  while(pos[0]<n-p+1)
  {
    i=p-1;
    while(pos[i]<n)
    {
      //Imprime a seleção atual da sequência, conforme explicado acima
      imp(n,p,vet,pos);
      /*A posição do último elemento escolhido é alterada até que se
      chegue ao final do vetor de entrada.*/
      pos[i]++;
    }
    /*Nesta parte do algoritmo, deseja-se encontrar a primeira posição,
    a partir da última (voltando, é lógico), de modo que não forme um
    bloco único. Em outras palavras, você vai voltar para o marcador
    da posição do penúltimo elemento selecionado. Se este tiver o índice
    do vizinho do último elemento, então você repete o processo procurando
    o penúltimo e assim por diante.*/
    j=i-1;
    while(pos[i]-pos[j]==1)
    {
      i--;
      j--;
    }
    /*Agora você incrementa a posição apontada pelo elemento encontrado
    para gerar as próximas combinações.*/
    pos[j]++;
    /*A partir da nova posição apontada por esse elemento, todos os marcadores
    das posições seguintes apontarão posições consecutivas*/
    while(i<p)
    {
      pos[i]=pos[j]+i-j;
      i++;
    }
  }
}
int main()
{
  int n,p,i;
  //Digite os valores de n e p, nesta ordem
  scanf("%d%d",&n,&p);
  //Digite os números a serem combinados
  int vet[n];
  for(i=0;i<n;i++)scanf("%d",&vet[i]);
  comb(n,p,vet);
  return 0;
}
