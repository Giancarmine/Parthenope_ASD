/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Class Array
Data    		: 10/10/2015

To Do:
-----------------------------------------------------------------------------------------------------*/

class Array{
    private:
        int* A;
        int N;

    public:
        //Array e gestione
            Array (){A = NULL;}; //Costruttore
            ~Array(){delete[] A;};
        void GetLength ( int );
        void Carica ();
        void Stampa ();
        void Swap ( int&, int& );
        void Compswap ( int&, int& );
        //Ordinamenti
        void InsectionSort ();
        void MergeSort ();
        //QuickSort
        int Partition ( int, int );
        void OrdinaQuick ( int, int );
        void QuickSort ();
};

//Swap
void Array :: Swap ( int &A, int &B ){
    int T=A;
    A=B;
    B=T;
}

void Array :: Compswap ( int &A, int &B ){
    if( B > A ) Swap( A, B );
}

void Array :: GetLength ( int Length ){
    N = Length;
}

//Carica N elemementi random al interno del Array A
void Array :: Carica (){
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
void Array :: Stampa () {
    int i;

    if(A == NULL){
        cout << "Array VUOTO!" << endl;
    }

    for (i=0; i<N; i++){
        cout << A[i] << "\t";
    }
    cout << endl;
}

/*==============================================================================
Autore : Carmine Cuofano
Data   : 15/12/2014
							InsectionSort
------------------------------------------------------------------------------*/
void Array :: InsectionSort ()
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
                Swap( A[i], A[j]);
            }
        }
    }
}

/*==============================================================================
Autore : Carmine Cuofano
Data   : 15/12/2014
							Merge
------------------------------------------------------------------------------
void Array :: Merge (int C[], int A, int N, int B[], int M){
    int i, J, K;
    for ( i=0, J=0, K=0; K < N+M; K++ ){
        if ( i == N ) {
                C[K] = B[J++];
        }
        else {
            if ( J == M ){
                C[K] = A[i++];
            }
            else {
                C[K] = A[i]<B[J] ? A [i++]:B [J++];
            }
        }
    }
}
/*==============================================================================
Autore : Carmine Cuofano
Data   : 15/12/2014
							MergeSort
------------------------------------------------------------------------------
void Array :: MergeSort (int C[], int A, int N, int B[], int M){
    int i, J, K;
    for ( i=0, J=0, K=0; K < N+M; K++ ){
        if ( i == N ) {
                C[K] = B[J++];
        }
        else {
            if ( J == M ){
                C[K] = A[i++];
            }
            else {
                C[K] = A[i]<B[J] ? A [i++]:B [J++];
            }
        }
    }
}

/*==============================================================================
Autore : Carmine Cuofano
Data   : 22/10/2015
							QuickSort
------------------------------------------------------------------------------*/

int Array :: Partition ( int l, int r ){
    int i = l-1,
        j = r;
    int V = A[r];
    for(j=0; j<i; j++){
        while( A[++i] < V );
        while( V < A[--j] ) if (j == l) break;
        if (i >= j) break;
        Swap(A[i],A[j]);
    }
    Swap(A[i],A[r]);
    return i;
}

void Array :: OrdinaQuick(int l, int r){
    int i;
    if (r <= l) return;
    i = Partition(l,r);
    OrdinaQuick(l,i-1);
    OrdinaQuick(i+1,r);
}

void Array :: QuickSort(){
    OrdinaQuick(0, N-1);
}
