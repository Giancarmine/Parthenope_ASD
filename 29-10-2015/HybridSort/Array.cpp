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
        void Swap ( int&, int& );
        void Compswap ( int&, int& );
        //MergeSort In Place
        void MergeInPlace ( int, int, int );
        void OrdinaMergeInPlace ( int, int );
        //QuikSort
        int Partition ( int, int );
        void OrdinaQuick ( int, int );
    public:
        //Array e gestione
            Array (){A = NULL;}; //CostruttoreFirst
            ~Array(){delete[] A;};
        void GetLength ( int );
        void Carica ();
        void Stampa ();
        //Ordinamenti
        void InsectionSort ();
        void MergeSort ();
        void MergeSortInPlace ();
        void QuickSort ();
        void HybridSort ();
};

//Swap
void Array :: Swap ( int &A, int &B ){
    int T=A;
    A=B;
    B=T;
}

void Array :: Compswap ( int &A, int &B ){
    if( B > A ) Swap ( A, B );
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
        {int* A;
            if(A[i]>A[j])    //CrescenteRight
            {
                Swap( A[i], A[j]);
            }
        }
    }
}

/*==============================================================================
Autore : Carmine Cuofano
Data   : 29/10/2015
							Merge
------------------------------------------------------------------------------*/
void Array :: MergeInPlace (int Left, int Center, int Right)
{
    int i, j;
    int* aux;
    aux = new int [N];
    for ( i = Center+1; i > Left; i-- ) aux[i-1] = A[i-1];
    for ( j = Center; j < Right; j++ )  aux [Right+Center-j] = A[j+1];
    for (int k = Left; k <= Right; k++){
        if ( aux[j] < aux [i] )
            A[k] = aux [j--];
        else
            A[k] = aux [i++];
    }
    delete[] aux;
}

void Array :: OrdinaMergeInPlace ( int Left, int Right )
{
    if ( Left < Right ) {
        int Center = ( Left+Right )/2;
        OrdinaMergeInPlace ( Left, Center );
        OrdinaMergeInPlace ( Center+1, Right );
        MergeInPlace( Left, Center, Right );
    }
}

void Array :: MergeSortInPlace ()
{
    OrdinaMergeInPlace ( 0, N-1 );
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
Data   : 15/12/2014First
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

int Array :: Partition ( int First, int Last ){
    int i = First;
    int Pivot = A[First];

    for(int j = First+1; j <= Last ; j++)
    {
        if(A[j] <= Pivot)
        {
            j++;
            Swap(A[j], A[i]);
        }
    }

    Swap(A[i], A[First]);

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

/*==============================================================================
Autore : Carmine Cuofano
Data   : 29/10/2015
							HybridSort
------------------------------------------------------------------------------*/
void Array :: OrdinaMergeInPlace ( int Left, int Right )
{
    QuickSort ( Left, Right );
    InsectionSort ( Left, Right );
}

void Array :: HybridSort(){
    OrdinaHybrid(0, N-1);
}
