#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define  TAM 10
#define COL 4
#define CAP 10
#define ERROR_ARCH 1
#define TODO_OK 0
typedef int (*Cmp)(void* , void*);
typedef void(*Mostrar)(void*);
typedef struct
{
    void* vec;
    int ce;
    size_t tam;
    int cap;
}Lista;
typedef struct
{
    int nroPedido;
    int nroArticulo;
    int cantidadPedida;
    float precioUnitario;
}Producto;


bool esLetra(char* a);
int cmpChar(void* a,void* b);
int eliminar(char* cad,char* caracterElim);
void moverCaracteres(char* cad);
void normalizar(char* cad,char* cadNormalizada);
bool ordenarBurbujeo(void * vec,int ce,size_t tam,Cmp cmp);
bool ordenarInsercion(void* vec,int ce,size_t tam,Cmp cmp);
int cmpEntero(void* a , void* b);
void intercambio(void* a , void * b,size_t tam);
bool anagramaVerificar(char* cad1,char* cad2);
int strcmp_mio(char* cad1,char *cad2);
int strlen_mio(char* cad);
char* obtenerPalabra(char* cad,char* palabra);
void ofuscar(char* cad,char* ofuscada);
void ofuscarPalabra(char* palabra,char* ofuscada);
void invertirPalabra(char* palabra);
void sumarCadena(char* palabra);
void restarCadena(char* palabra);
char* guardarOfuscada(char* dest,char* orig);
size_t strspn_mio(char* s1,char* s2);
void mostrarEspiral(int matriz[][COL],int f,int c);
float promedioDiagonalMatriz(int matriz [][COL],int f,int c);
void mostrarElemMatrizMayorA(int matriz[][COL],int c , int f);
void transponerinSitu(int matriz[][COL],int c,int f);
void crearLista(Lista* l,size_t tam);
void listaInsertarAlFinal(Lista* l,void* elem);
void mostrarLista(Lista* lista ,Mostrar mostrarProducto);
void mostrarProducto(void* p);
void mostrarInt(void* p);
int mostrarArchivo(char* n);
int crearArchivo(char* n,Lista* prod);

int main()
{
    ///-1

    /*
    int nElim= 0;
    char cad[60];
    strcpy(cad,"Algo que se me ocurrio");
    nElim= eliminar(cad,"EIOU");
    printf("%s -- y han sido eliminados %d elementos",cad,nElim);*/
    ///-2
   /* char cad[100] = "	cEnTrO    sUd 	";
    char cadNormalizada[100];
    normalizar(cad,cadNormalizada);
    printf("%s",cadNormalizada);*/
    ///-3
    /*int v[] = {0,3,1,4,2};
    ordenarBurbujeo(v,5,sizeof(int),cmpEntero);*/
    ///-4
    /*char cad1 [] = "jaimtoi";
    char cad2 [] = "jaimito";
    anagramaVerificar(cad1,cad2);*/
    ///-5
    /*char cad[TAM] = "hay unos";
    printf("%d\n",strlen(cad));
    char cadOfuscada[TAM];
    ofuscar(cad,cadOfuscada);
    printf("%s\n",cadOfuscada);*/
    ///-6
    /*char s1[13] = "Hola a todos";
    char s2[5] = "Hola";
    printf( "s1=%s\n", s1 );
    printf( "s2=%s\n", s2 );
    printf( "strspn(s1,s2) = %d\n", strspn( s1, s2 ) );
    printf( "strspn(s1,s2) = %d\n", strspn_mio( s1, s2 ) );*/
    ///-7
    int matriz [][4] = {
                        {1,2,3,4},
                        {4,5,6,7},
                        {8,9,10,11},
                        {12,13,14,15}

    };


    mostrarMatrizCaracol(4,4,matriz);
    ///-8
    /*int matriz [][COL] = {
                        {5,2,3,9},
                        {9,3,4,8},
                        {1,6,8,1},
                        {1,6,8,5}

    };
    transponerinSitu(matriz,4,COL);*/
    ///-9
    /*Producto a = {1,10,750,15000.5};
    Producto b = {2,45,250,8760.5};
    Producto c = {3,30,135,3500.5};
    Producto d = {4,15,500,12000.5};
    Producto e = {5,19,558,1900.5};

    Lista l;
    crearLista(&l,sizeof(Producto));
    listaInsertarAlFinal(&l,&a);
    listaInsertarAlFinal(&l,&b);
    listaInsertarAlFinal(&l,&c);
    listaInsertarAlFinal(&l,&d);
    listaInsertarAlFinal(&l,&e);
    mostrarLista(&l,mostrarProducto);
    char nombre [] = "Producto.bin";
    crearArchivo(nombre,&l);
    procesarArchivo(nombre,"mayores.bin","menores.bin");
    mostrarArchivo("mayores.bin");
    printf("\n");
    mostrarArchivo("menores.bin");*/

    ///-10
    /*int matriz [][COL] = {
                        {5,2,3},
                        {9,3,4},
                        {1,6,8}

    };
    mostrarElemMatrizMayorA(matriz,COL,3,matrizTranspuesta);*/

    return 0;
}
void mostrarMatrizCaracol(int m, int n, int a[][COL])
{
    int i, k = 0, l = 0;

    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n) {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i) {
            printf("%d ", a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns
         */
        for (i = k; i < m; ++i) {
            printf("%d ", a[i][n - 1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if (k < m) {
            for (i = n - 1; i >= l; --i) {
                printf("%d ", a[m - 1][i]);
            }
            m--;
        }

        /* Print the first column from the remaining columns
         */
        if (l < n) {
            for (i = m - 1; i >= k; --i) {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}

int crearArchivo(char* n,Lista* prod)
{
    FILE* arch = fopen(n,"wb");
    if(!arch)
    {
        puts("Error al crear el archivo producto");
        return ERROR_ARCH;
    }
    fwrite(prod->vec,prod->tam,prod->ce,arch);
    fclose(arch);
    return TODO_OK;
}
int mostrarArchivo(char* n)
{
    Producto prod;
    FILE* arch = fopen(n,"rb");
    if(!arch)
    {
        return ERROR_ARCH;
    }
    fread(&prod,sizeof(Producto),1,arch);
    while(!feof(arch))
    {
        printf("%d|%d|%d|%f\n",prod.nroPedido,prod.nroArticulo,prod.cantidadPedida,prod.precioUnitario);
        fread(&prod,sizeof(Producto),1,arch);
    }
    fclose(arch);
    return TODO_OK;
}
int procesarArchivo(char* nameRead,char* mayores,char* menores)
{
    Producto prod;
    FILE* arch_read  = fopen(nameRead,"rb");
    if(!arch_read)
    {
        return ERROR_ARCH;
    }
    FILE* arch_may = fopen(mayores,"wb");
    if(!arch_may)
    {
        fclose(arch_read);
        return ERROR_ARCH;
    }
    FILE* arch_men = fopen(menores,"wb");
    if(!arch_men)
    {
        fclose(arch_read);
        fclose(arch_may);
        return ERROR_ARCH;
    }
  fread(&prod,sizeof(Producto),1,arch_read);
  while(!feof(arch_read))
  {
      if(prod.precioUnitario > 10000)
      {
          fwrite(&prod,sizeof(Producto),1,arch_may);
      }
      else
      {
            fwrite(&prod,sizeof(Producto),1,arch_men);
      }
      fread(&prod,sizeof(Producto),1,arch_read);

  }
  fclose(arch_read);
  fclose(arch_men);
  fclose(arch_may);
  return TODO_OK;
}
void mostrarInt(void* p)
{
    int* a = (int*) p;
    printf("%d\n",*a);
}
void crearLista(Lista* l,size_t tam)
{
    l->vec = malloc(tam*CAP);
    l->cap = CAP;
    l->tam = tam;
    l->ce = 0;
}
/*void mostrarProducto(void* p)
{
    Producto* prod = (Producto*)p;
    printf("%d",prod->nroPedido);
}*/
void mostrarProducto(void* p) {
    Producto* prod = (Producto*)p;
    printf("nroPedido: %d, campo2: %d, campo3: %d, campo4: %f\n",
           prod->nroPedido, prod->nroArticulo, prod->cantidadPedida, prod->precioUnitario);
}

void mostrarLista(Lista* l,Mostrar mostrar)
{
    int tam = l->tam;
    int ce = l->ce;
    void * p = l->vec;
    while(ce)
    {
        mostrar(p);
        p+=tam;
        ce--;
    }
    printf("\n");
}

void listaInsertarAlFinal(Lista* l,void* elem)
{
    if(l->ce == l->cap)
    {

        l->vec = realloc(l->vec,l->ce*2*l->tam);
        l->cap*=2;
    }
    void* p = l->vec;
    p+=l->ce*l->tam;
    memcpy(p,elem,l->tam);
    l->ce++;

}

void transponerinSitu(int matriz[][COL],int c,int f)
{
    int r = 0;
    for(int i = 0;i<c;i++)
    {
        for(int j = 1+r ; j<f;j++)
        {
            intercambio(&matriz[i][j],&matriz[j][i],sizeof(int));
        }
        r++;
    }
}

void mostrarElemMatrizMayorA(int matriz[][COL],int c , int f)
{
    float promedio;
     if((promedio = promedioDiagonalMatriz(matriz,f,c)) >=0)
     {
         printf("el promedio es %f\n",promedio);
         for(int i = 0;i<f;i++)
         {
             for(int j = 0;j<c;j++)
             {
                 if(matriz[i][j]>promedio)
                 {
                     printf("%d\n",matriz[i][j]);
                 }
             }
         }
     }
     else
        puts("Error al hallar el promedio");


}
float promedioDiagonalMatriz(int matriz [][COL],int f,int c)
{
    int n = 0;
    float acu = 0;
    for(int i = 0;i<f;i++)
    {
        acu += matriz[i][i];
        n++;
    }
    if(n>0)
    {
        return acu/n;
    }
    else
    {
        return -1;
    }
}

size_t strspn_mio(char* s1,char* s2)
{
    int i = 0;
    char* s2_ini = s2;
    while((*s1 && *s2) && *s1==*s2 )
    {
        s1++;
        s2++;
        i++;
        if(!*s2)
        {
            s2 = s2_ini;
        }

    }
    return i;
}
void ofuscar(char* cad,char* ofuscada)
{
    char palabra[strlen(cad)];
    while(*cad)
    {
        bool palabraOfucada = false;
        while(*cad && *cad == ' ')
        {
            cad++;

        }

        if(*cad)
        {
            cad = obtenerPalabra(cad,palabra);
            ofuscarPalabra(palabra,ofuscada);
            ofuscada = guardarOfuscada(ofuscada,palabra);
            palabraOfucada = true;
        }
        if(*cad && palabraOfucada == true)
        {
            *ofuscada = ' ';
            ofuscada++;
        }

    }
    *ofuscada = '\0';

}
char* guardarOfuscada(char* dest,char* orig)
{
    while(*orig)
    {
        *dest++ = *orig++;
    }
    return dest;
}
void ofuscarPalabra(char* palabra,char* ofuscada)
{
    int longitud = strlen(palabra);
    if(longitud % 2 == 0)
    {
          sumarCadena(palabra);
          invertirPalabra(palabra);
    }
    else
    {
        invertirPalabra(palabra);
        restarCadena(palabra);
    }


}

void sumarCadena(char* palabra)
{
    while(*palabra)
    {
        if(*palabra == 'z')
        {
            *palabra = 'A';
        }
        else if(*palabra == 'Z')
        {
            *palabra = 'a';
        }
        else
        {
            *palabra=(*palabra+1);
        }
        palabra++;
    }
}
void restarCadena(char* palabra)
{
    while(*palabra)
    {
        if(*palabra == 'a')
        {
            *palabra = 'Z';
        }
        else if(*palabra == 'A')
        {
            *palabra = 'a';
        }
        else
        {
            *palabra= *palabra-1;
        }
        palabra++;
    }
}

void invertirPalabra(char* palabra)
{
    int ce = strlen(palabra);
    char* temp = malloc(ce+1);
    char* ini = temp;
    char* inverso = palabra+ce-1;
    for(int i = 0;i<ce;i++)
    {
        *temp= *inverso;
        temp++;
        inverso--;
    }
    *temp = '\0';
    strcpy(palabra,ini);
    temp = ini;
    free(temp);


}
char* obtenerPalabra(char* cad,char* palabra)
{
    ///hol_
    while(esLetra(cad) && *cad)
    {
        *palabra++ = *cad++;
    }
    *palabra = '\0';
    return cad;
}
int cmpChar(void* a,void* b)
{
    return *(char*)a - *(char*)b;
}
int cmpEntero(void* a , void* b)
{
    return *(int*)a - *(int*)b;
}
void moverCaracteres(char* cad)
{
    while(*cad)
    {
        *cad = *(cad+1);
        cad++;
    }
}
int eliminar(char* cad,char* caracterElim)
{
    char* cadIni = cad;
    int n = 0;
    while(*caracterElim)
    {
        while(*cad == ' ')
        {
            cad++;
        }
        while(*cad)
        {
            if(*cad == *caracterElim)
            {
                moverCaracteres(cad);
                n++;
            }
            cad++;
        }
        cad = cadIni;
        caracterElim++;

    }
    return n;
}

void guardarPalabra(char* palabra,char* cad)
{
    while(*cad == ' ' && *cad)
    {
        cad++;
    }
    while(esLetra(cad) && *cad)
    {
        *palabra++ = *cad++;
    }
    palabra = '\0';

}
bool anagramaVerificar(char* cad1,char* cad2)
{

    char palabra1[strlen(cad1)];
    char palabra2[strlen(cad2)];
    guardarPalabra(palabra1,cad1);
    guardarPalabra(palabra2,cad2);
    int palabra1_ce = strlen_mio(palabra1) ;
    int palabra2_ce = strlen_mio(palabra2);
    if(palabra1_ce != palabra2_ce)
    {
        puts("No es anagrama");
        return false;
    }
    ordenarBurbujeo(palabra1,palabra1_ce,sizeof(char),cmpChar);
    ordenarBurbujeo(palabra2,palabra2_ce,sizeof(char),cmpChar);
    if(strcmp(palabra1,palabra2) == 0)
      {
        puts("Es anagrama");
        return true;
      }
    else
    {
        puts("No es anagrama");
        return false;
    }

}
int strcmp_mio(char* cad1,char *cad2)
{
    while(*cad1 && *cad2)
    {
        if(*cad1 > *cad2)
        {
            return 1;
        }
        else if(*cad1 < *cad2)
        {
            return -1;
        }

    }
    return 0;
}
int strlen_mio(char* cad)
{
    int n = 0;
    while(*cad)
    {
        n++;
        cad++;
    }
    return n;
}
/*Ejercicio 2: Desarrollar una función que reciba una cadena de caracteres y la normalice.
Ej.: "	cEnTrO    sUd 	"  ==>  "Centro Sud"*/
bool esLetra(char* a)
{
    if((*a >= 'a' && *a<='z') || (*a>='A' && *a<='Z'))
        return 1;
    else
        return 0;
}
void aMiniscula(char* c)
{
    if(*c >= 'A' && *c<='Z')
    {
        *c +=32;
    }
}
void aMayuscula(char* c)
{
    if(*c >= 'a' && *c<='z')
    {
        *c -=32;
    }
}
void normalizar(char* cad,char* cadNormalizada)
{

    bool finDeCadena = false;
    while(*cad)
    {
        bool palabraEscrita = false;
        while((*cad==' ' || !esLetra(cad))  &&   *cad)
        {
            cad++;
        }
        if(*cad && esLetra(cad))
        {
            palabraEscrita = true;
            *cadNormalizada = *cad;
            cad++;
            aMayuscula(cadNormalizada);
            cadNormalizada++;
        }
        while(*cad && esLetra(cad))
        {
            palabraEscrita = true;
            *cadNormalizada = *cad;
            cad++;
            aMiniscula(cadNormalizada);
            cadNormalizada++;
        }
        if(!*cad)
        {
            finDeCadena = true;
        }
        if(!finDeCadena && palabraEscrita)
        {
            *cadNormalizada=' ';
            cadNormalizada++;
        }
    }
    *cadNormalizada = '\0';

}
bool ordenarBurbujeo(void * vec,int ce,size_t tam,Cmp cmp)
{
    ///5,6,3,1,9,10,25,31
    ///5,3,1,6,9,10,25,31
    ///3,1,5,6,9,10,25,31
    ///1,3,5,6,9,10,25,31
    void * fin = vec + (ce - 1)*tam;
    for(int i= 0;i<ce;i++)
    {
        for(void * j = vec ; j<fin ; j+=tam)
        {
            if(cmp(j,j+tam) > 0)
            {
                intercambio(j,j+tam,tam);
            }
        }
    }
    return 0;
}

void intercambio(void* a , void * b,size_t tam)
{
    void* aux = malloc(tam);
    memcpy(aux,a,tam);
    memcpy(a,b,tam);
    memcpy(b,aux,tam);
    free(aux);
}


