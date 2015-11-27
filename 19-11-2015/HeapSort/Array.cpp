/*===================================================================================================

Autore  	    : Carmine Cuofano											Matricola: 0124001424
Programma   	: Class Array
Data    		: 10/10/2015

To Do:
 - Rimpiazzare min e max con i metodi della classe
 - Creare array.h con le definizioni
-----------------------------------------------------------------------------------------------------*/

class Array{
    private:
        vector <int> A;
        int N;
        void Swap ( int&, int& );
        void Compswap ( int&, int& );
        //MergeSort In Place
        void MergeInPlace ( int, int, int );
        void OrdinaMergeInPlace ( int, int );
        //QuikSort
        int Partition ( int, int );
        void OrdinaQuick ( int, int );
        //HeapSort
    public:
        //Array e gestione
            Array (){}; //Costruttore
            ~Array(){};
        void GetLength ( int );
        void Carica ();
        void Stampa ();
        //Ordinamenti
        void InsectionSort ();
        void MergeSort ();
        void MergeSortInPlace ();
        void QuickSort ();
        void CountingSort ();
        void BucketSort ();
        //Heap Gestione e Ordinamenti
        void BuildMaxHeap ();
        void MaxHeapify ();
        void HeapSort ();
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

    for (i=0; i<N; i++){
        //Per numeri interi -Definizione a 15 bit-
        A.push_back( (rand()%100)+1 );
    }
}
//Stampa il contenuto Del Array A
void Array :: Stampa () {
    int i;

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
							Mergevoid Array :: CountingSort (){
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
Data   : 30/10/2015
							CountingSort
------------------------------------------------------------------------------*/

void Array :: CountingSort (){
    int Max, Min, i, M;

    Max = Min = A[0];

    for( i = 0; i < N-1; i++ ){
        if(A[i]>Max) Max = A[i];
        else if( A[i] < Min ) Min = A[i];
    }

    //Definisco la lunghezza del Vectotr di Counting
    M = Max-Min+1;
    vector <int> C(M,0);
    for ( i = 0; i < N; i++ ) C[A[i]-Min]++;

    int k=0;          //indice per l'array A
    for( i = 0; i < M; i++ ){
        int valore=i+Min;
        while(C[i]>0){ //scrive C[i] volte il valore nell'array A
            A[k++]=i+Min;
            C[i]--;
        }
    }
    C.clear ();
}


/*==============================================================================
Autore : Carmine Cuofano
Data   : 05/11/2015
							BucketSort
------------------------------------------------------------------------------*/
void Array :: BucketSort (){
    int i,
        Max,
        Min,
        j,
        Step,
        M = 6; // Numero di bucket
    list <int> C[M];//Creo i Bucket


    //Trovo il minimo e il massimo
    Max = Min = A[0];

    for( i = 0; i < N-1; i++ ){
        if(A[i]>Max) Max = A[i];
        else if( A[i] < Min ) Min = A[i];
    }

    //Definisco il range dei bucket
    Step = ( Max - Min + 1 ) / ( M - 1 );   //Arrotondato

    //Posiziono nei Bucket
    for ( i=0; i<N-1; i++ ){
        C[(A[i] - Min)/Step].push_back ( A[i] );
    }

    //Ordina i Bucket
    for ( j=0; j<M-1; j++ ){
        C[j].sort ();
    }

    //Concatena i Bucket
    A.clear ();
    for ( j=0; j<M; j++ ){
        for ( //iterator )
            A.push_back (C[j]);
    }
}


/*HeapSort
l= Left[i]
r=Right[i]
if A[i] < A[l] && l < heapsize[A]
  then max=l
  else max=i
if A[max] < A[r]
  then max=r
if max != i && r < heapsize[A]
   then scambia A[i] <--> A[max]
           Max-Heapify(A,max)
*/
