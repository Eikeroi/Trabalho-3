#include <stdio.h>
#include <stdlib.h>



  struct elem{
      int x;
      int y;
      struct elem *prox;
      float valor;
  };

typedef struct elem elemento;
typedef elemento *elemento_ptr;

elemento_ptr BuscaElemento(elemento_ptr Lista, int x, int y)
{
	while (Lista != NULL && (Lista->x != x || Lista->y != y))
		Lista = Lista->prox;

	return Lista;
}


void insert(elemento_ptr *Lista, int x, int y, float valor){
    elemento_ptr novo=BuscaElemento(*Lista,x,y);
    if(novo!=NULL){
        novo->valor=valor;
        return;
    }
    novo = (elemento_ptr)malloc(sizeof(elemento));
    elemento_ptr atual= *Lista;
    elemento_ptr prev = NULL;
    novo->x=x;
    novo->y=y;
    novo->valor=valor;
    novo->prox=NULL;

    if(atual==NULL){
        *Lista=novo;
        return;
    }
    if((atual->y>y)||(atual->y==y&&atual->x>x)){
        *Lista=novo;
        novo->prox=atual;
        return;
    }

    while(atual != NULL){
        if((atual->y>y)||(atual->y==y&&atual->x>x)){
            prev->prox=novo;
            novo->prox=atual;
            break;
        }
        prev = atual;
        //printf("cdaadad%f\n", atual->valor);
        atual = atual->prox;
    }
    if (atual==NULL){
        prev->prox=novo;
        novo->prox=NULL;
    }



}

void printlista(elemento_ptr Lista){
    elemento_ptr atual = Lista;

    while(atual != NULL){
        printf("%f\n", atual->valor);
        atual = atual->prox;
    }
}

void livre(elemento_ptr *Lista){
    elemento_ptr atual=*Lista;
    elemento_ptr prev;
while(atual != NULL){
        prev=atual;
        atual = atual->prox;
        free(prev);
    }

*Lista=NULL;
}

void somlin (int y,elemento_ptr Lista ){
elemento_ptr atual=Lista;
float soma=0;
 while(atual != NULL){

        if(atual->y==y){
            soma=soma+atual->valor;
        }

        atual = atual->prox;
    }
printf("\n%.2f\n", soma);
}

void somcol (int x,elemento_ptr Lista ){
elemento_ptr atual=Lista;
float soma=0;
 while(atual != NULL){

        if(atual->x==x){
            soma=soma+atual->valor;
        }

        atual = atual->prox;
    }
printf("\n%.2f\n", soma);
}

void printelemento(elemento_ptr Lista, int x, int y){
elemento_ptr atual=BuscaElemento(Lista,x,y);
if(atual!=NULL){
    printf("\n%f\n", atual->valor);
}else{
printf("\n0\n");
}


}




int main()
{
    int existencia=0;
    elemento_ptr Lista = NULL;
    int col;
    int lin;
    int colmax;
    int linmax;
    float valor;
    while(1){
        int opcao=0;
        printf("Insira 1 para criar matriz;\n2, para atribuir um valor;\n3, para consultar um valor;\n4, para exibir a soma de uma linha ou coluna;\n5, para excluir matriz;\n0, para encerrar o programa;\n");
        fflush(stdin);
        scanf("%d", &opcao);
        if(opcao==1){
                if(existencia==1){
                    printf("\nJa existe uma matriz, exclua antes de criar outra\n");
                }else{
                int valido=0;
        while(valido==0){
            printf("Insira o numero de linhas que a matriz tera:  ");
            fflush(stdin);
            scanf("%d", &linmax);
            if(linmax>=1){
                valido=1;
            }else{
            printf("\nA matriz deve ter uma quantidade positiva de linhas\n");
            }
        }
            valido=0;
        while(valido==0){
            printf("Insira o numero de colunas que a matriz tera:  ");
            fflush(stdin);
            scanf("%d", &colmax);
            if(colmax>=1){
                valido=1;
            }else{
            printf("\nA matriz deve ter uma quantidade positiva de colunas\n");
            }
        }
        existencia=1;
                }
        }

        //*&%*&%&*%&*%*%*&%&*%&**%*&%&%*%&*%&%&*%*&&%*

        if(opcao==2){

                if(existencia==0){
                    printf("\n nao ha matrizes, crie uma antes.\n");
                }else{

                int valido=0;

                while(valido==0){
            printf("\nInsira a linha do elemento: ");
            fflush(stdin);
            scanf("%d", &lin);
        if(lin<=linmax&&lin>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a linha %d e deve ser positiva.", linmax);
        }
                }
                valido=0;
             while(valido==0){
            printf("\nInsira a coluna do elemento: ");
            fflush(stdin);
            scanf("%d", &col);
        if(col<=colmax&&col>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a coluna %d e deve ser positiva.", colmax);
        }
                }
            printf("\nInsira o valor do elemento: ");
            fflush(stdin);
            scanf("%f", &valor);
            insert(&Lista,col,lin,valor);
                }
        }

//*&%$%#@$%*&*$#$%@#$%$#$%*&*;;$#@#$@#$#$#%&*&*&#$#$
if(opcao==3){
        if(existencia==0){
            printf("\n nao ha matrizes, crie uma antes.\n");
        }else{
         int valido=0;

                while(valido==0){
            printf("\nInsira a linha do elemento: ");
            fflush(stdin);
            scanf("%d", &lin);
        if(lin<=linmax&&lin>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a linha %d e deve ser positiva.", linmax);
        }
                }
                valido=0;
             while(valido==0){
            printf("\nInsira a coluna do elemento: ");
            fflush(stdin);
            scanf("%d", &col);
        if(col<=colmax&&col>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a coluna %d e deve ser positiva.", colmax);
        }
                }


        printelemento(Lista,col, lin );
        }
}
//*&&@##!#$#@$$$%%&*&$#$%%*&**#@#!#$*%*%*$#$#@%$#%$***&&

if(opcao==4){
        int valido=0;
        if(existencia==0){
            printf("\n nao ha matrizes, crie uma antes.\n");
        }else{
        int qsoma=0;
    printf("\nInsira 1 para exibir soma de linha e 2 para soma de coluna: ");
    fflush(stdin);
    scanf("%d", &qsoma);
    if(qsoma==1){


            while(valido==0){
            printf("\n Insira o numero da linha que quer somar:  ");
        fflush(stdin);
        scanf("%d",&lin);
        if(lin<=linmax&&lin>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a linha %d e deve ser positiva.", linmax);
        }
                }

        somlin(lin, Lista);
    }
    if(qsoma==2){



        valido=0;
             while(valido==0){
           printf("\n Insira o numero da coluna que quer somar:  ");
        fflush(stdin);
        scanf("%d",&col);
        if(col<=colmax&&col>=1){
            valido=1;
        }else{
        printf("\nA matriz so vai ate a coluna %d e deve ser positiva.", colmax);
        }
                }
        somcol(col, Lista);
    }
        }
}
if(opcao==5){
if(existencia==0){
    printf("\n nao ha matrizes, crie uma antes.\n");
}else{
livre(&Lista);
existencia=0;
}

}

if(opcao==0){
    break;
}

    }


    livre(&Lista);
}
