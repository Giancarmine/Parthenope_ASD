/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Class Array
Data    		: 10/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

class Array{
    private:
        int* A;

    public:
            Array (){A = NULL;}; //Costruttore
        void InsectionSort (int);
        void Carica (int);
        void Stampa (int);
        ~Array(){delete[] A;}
};

//Carica N elemementi random al interno del Array A
void Array :: Carica (int N){
    int i;

    A = new int [N];
    if(A == NULL){
        cout << "Impossibile Allocare memoria per l`Array" << endl;
    }

    for (i=0; i<N; i++){
        A[i] = (rand()%100)+1;
    }
}
//Stampa il contenuto Del Array A
void Array :: Stampa (int N) {
    int i;

    if(A == NULL){
        cout << "Array VUOTO!" << endl;
    }

    for (i=0; i<N; i++){
        cout << A[i] << endl;
    }
}

/*==============================================================================
Autore : Carmine Cuofano
Data   : 15/12/2014
							InsectionSort
------------------------------------------------------------------------------*/
void Array :: InsectionSort (int N)
{
    int i  ,     //Indice
        j  ,	 //Cella successiva a quella puntata
        App;     //Variabile di Appoggio


    for(i=0 ; i < N-1 ; i++)
    {
        for(j = i+1 ; j < N ; j ++)
        {
            if(A[i]>A[j])    //Crescente
            {
                App  = A[i];
                A[i] = A[j];
                A[j] = App;
            }
        }
    }
}
