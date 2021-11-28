#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

/* yapýlan iþlemler 
1- N sayýsýný giriyoruz ( 1. aþamada n elemaný olarak )
2- Aralýðý giriyoruz 2. aþamada 300 girersek 0-300 arasýndaki sayýlardan seçiyor örneðin - n=10 ve max= 50 seçersek, 10 tane 0-50 arasýnda sayý oluþturuyor.
3- Sýralama seçeneði seçiyoruz kendisi otomatik olarak sýralýyor ve süresini yazýyor.

a- countSort bir problem var çalýþýyor
b- bubble sort çalýþýyor
c- selection sort  yapýldý calýsýyor
d- Eklemeli yapýldý calýsýyor
e- birlestirme ++ birlestirme yapildi
f- sansli + aciklama yapildi
*/

int getMax(int a[], int n) {  
   int max = a[0];  
   for(int i = 1; i<n; i++) {  
      if(a[i] > max)  
         max = a[i];  
   }  
   return max; //maximum element from the array  
}  
  
void countSort(int a[], int n) // function to perform counting sort  
{  
   int output[n+1];  
   int max = getMax(a, n);  
   int count[max+1]; //create count array with size [max+1]  
  
  
  for (int i = 0; i <= max; ++i)   
  {  
    count[i] = 0; // Initialize count array with all zeros  
  }  
    
  for (int i = 0; i < n; i++) // Store the count of each element  
  {  
    count[a[i]]++;  
  }  
  
   for(int i = 1; i<=max; i++)   
      count[i] += count[i-1]; //find cumulative frequency  
  
  /* This loop will find the index of each element of the original array in count array, and 
   place the elements in output array*/  
  for (int i = n - 1; i >= 0; i--) {  
    output[count[a[i]] - 1] = a[i];  
    count[a[i]]--; // decrease count for same numbers  
}  
  
   for(int i = 0; i<n; i++) {  
      a[i] = output[i]; //store the sorted elements into main array  
   }  
   for (int i = 0; i < n; i++)  
        cout<<output[i]<<" ";  
}  


void bubbleSort(int *sayi,int max){
	int temp; // Geçiçi deðiþken.
	for(int i=0; i<=max; i++){
		for(int j=i; j<=max; j++){
			// Dizideki sayý çiftlerini kontrol et.
			if(sayi[i] > sayi[j]){
				// Yanlýþ sýralanmýþ sayý çiftlerinin yerini deðiþtir.
				temp = sayi[i];
				sayi[i] = sayi[j];
				sayi[j] = temp;
			}
		}
	}
	for(int i=0;i<max;i++){
		cout<<i<< ". eleman ve gelen array => "<< sayi[i]<< " \n";
	}

}

void selectionSort(int *sayi,int max){
	int temp; // Geçiçi deðiþken.
	 for(int i = 0; i < max; i++) {  
  
        int min[2] = {99999, 0};  
  
        for (int m = i; m < max; m++) {  
  
            if (min[0] > sayi[m]) {  
                min[0] = sayi[m];  
                min[1] = m;  
            }  
  
        }  
  
        temp = sayi[min[1]];  
        sayi[min[1]] = sayi[i];  
        sayi[i] = temp;  

    }  
  
    for (int b = 0; b < max; b++) {  
  
        cout << " | " << sayi[b] << " | ";  
    }  
}


void insertionSort(int *arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

// Merge sort in C++

#include <iostream>
using namespace std;

// Merge two subarrays L and M into arr
void merge(int arr[], int p, int q, int r) {
  
  // Create L ‹ A[p..q] and M ‹ A[q+1..r]
  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  // Maintain current index of sub-arrays and main array
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

  // Until we reach either end of either L or M, pick larger among
  // elements L and M and place them in the correct position at A[p..r]
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  // When we run out of elements in either L or M,
  // pick up the remaining elements and put in A[p..r]
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

// Divide the array into two subarrays, sort them and merge them
void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    // m is the point where the array is divided into two subarrays
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    // Merge the sorted subarrays
    merge(arr, l, m, r);
    
    for (int i = 0; i <= r; i++)
    cout << arr[i] << " ";
  cout << endl;
  }
}
 


int main(){
	int n;
	int type;
	cout<< "Eleman sayisini girin : ";
	cin>>n;
	cout<<"Rastgele secilecek sayi icin maksimum deger girin (ornegin 0-100 icin 100 girebilirsiniz):";
	int max;
	cin >> max;
	cout <<"Sort islemi icin yontem belirleyin, yontemler icin rakam yazmaniz yeterli. \n";
	cout<< "1_Sayarak siralama(Counting sort)\n";
	cout<< "2_Kabarcik siralama(Buble sort)\n";
	cout<< "3_Secerek siralama(Selection sort)\n";
	cout<< "4_Eklemeli siralama(Insertion sort)\n";
	cout<< "5_Birlestirme siralama(Merge sort)\n";
	cout<< "6_Sansli siralama(Lucky sort)\n";
	cout <<"Hangisini secmek istersin:";
	cin >> type;
	int sayilar[n];
	for (int i=0;i<n;i++)
	{
		sayilar[i]=rand() %max;
	}
	for(int i=0;i<n;i++)
	{
		cout<<i+1<<".sayi = "<<sayilar[i]<<"\n";
	}
	switch(type){
		case 1:
			countSort(sayilar,n);
			break;
		case 2:
			bubbleSort(sayilar,n);
			break;
		case 3:
			selectionSort(sayilar,n);
			break;
		case 4:
			insertionSort(sayilar,n);
			break;
		case 5:
			mergeSort(sayilar,0,n-1);
			break;
		case 6:
			cout<<"Lucky sort sadece teorik olarak vardir,Dizin siralanmasi veya sorgulanmasina gerek yoktur.";
			break;
		default :
			cout<<"yanlis veya farkli bir secim yaptiniz";
			break;
		
	}
	
}

