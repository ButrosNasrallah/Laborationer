/* h filen från laboration 2
#ifndef LIST_H
#define LIST_H

#include <nrfx.h>

/*******************************************************/
/* DVA270 - Interface för dubbellänkad lista           */
/* Anpassad efter interface från DVA244                */
/* av Stefan Bygde och Caroline Uppsäll                */
/* Vid fel eller frågor, kontakta jonas.larsson@mdu.se */
/*******************************************************/


typedef int Data;

/*******************************************************/
/* Avkommentera den struktdefinition ni vill använda,  */
/* Beroende på om ni vill implementera en enkel- eller */
/* dubbellänkad lista.                                 */
/*******************************************************/


//struktdefinition för dubbellänkad lista
/*
typedef struct node
{
	Data data;
	struct node* next;
	struct node* previous;
}Node;



//struktdefinition för enkellänkad lista
*/
typedef struct node
{
	Data data;
	struct node* next;
}Node;

typedef Node* List;

/*
typedef Node *List; //Listan representeras av en nodpekare. 

/* Funktionsdeklarationer */

/*
//Returnera en tom lista
*/
List create_empty_list(void);
/*
//Är listan tom?
//Returnerar 1 om listan är tom, annars 0
int is_empty(const List list);
*/
//Lägg till en nod först i listan
void add_first(List *list, const Data data);
/*
//Lägg till nod sist i listan
void add_last(List *list, const Data data);

//Ta bort första noden i listan
void remove_first(List *list);

//Ta bort sista noden i listan
void remove_last(List *list);

//Töm listan (ta bort alla noder ur listan)
void clear_list(List *list);
*/
//Skriv ut listan genom UART
void print_list(const List list);
/*
//Returnera första datat i listan
Data get_first_element(const List list);

//Returnera sista datat i listan
Data get_last_element(const List list);

//Returnera hur många noder som finns i listan
int number_of_nodes(const List list);

//Sök efter data i listan, returnera 1 om datat finns, annars 0.
int search(const List list, const Data data);

//Ta bort data ur listan (första förekomsten), returnera 0 om datat inte finns, annars 1
int remove_element(List *list, const Data data);


#endif
*/



#ifndef BSTREE_H
#define BSTREE_H

#include <nrfx.h>

/*******************************************************/
/* DVA270 - Interface för binärt sökträd               */
/* Anpassad efter interface från DVA244                */
/* av Stefan Bygde och Caroline Uppsäll                */
/* Vid fel eller frågor, kontakta jonas.larsson@mdu.se */
/*******************************************************/

struct treeNode
{
	int data;
	struct treeNode* left;
	struct treeNode* right;
};


typedef struct treeNode* BSTree;

/* Skapar ett tomt trad */
BSTree create_empty_tree(void);

/* Returnerar 1 ifall trädet är tomt, 0 annars */
int is_empty(const BSTree tree);

/* Sätter in 'data' sorterat i *tree*/
void insert_sorted(BSTree* tree, int data);

/* Utskriftsfunktioner*/
void print_preorder(const BSTree tree);
void print_inorder(const BSTree tree);
void print_postorder(const BSTree tree);

/* Returnerar 1 om 'data' finns i tree, 0 annars */
int find(const BSTree tree, int data);

/* Tar bort 'data' från trädet om det finns */
void remove_element(BSTree* tree, int data);

/* Returnerar hur många noder som totalt finns i trädet */
int number_of_nodes(const BSTree tree);

/* Returnerar hur djupt trädet är */
int depth(const BSTree tree);

/* Returnerar minimidjupet för trädet */
int min_depth(const BSTree tree);

/* Balansera trädet sa att depth(tree) == min_depth(tree) */
void balance_tree(BSTree* tree);

/* Töm trädet och frigör minnet för de olika noderna */
void free_tree(BSTree* tree);

/* Returnerar 1 om arrayen som kommer från trädet är sorterad i stigande ordning, annars 0 */
int is_sorted_array(const int* arr, int size);

/* Returnerar 1 om själva trädet är sorterat i stigande ordning, annars 0 */
int is_sorted(const BSTree tree);

/* Fyller en array med slumpmässiga heltal mellan min och max */
void fill_random_array(int* arr, int size, int min, int max);

/* Skapar ett binärt sökträd med slumpmässiga värden mellan min och max */
BSTree create_random_tree(int size, int min, int max);

/* Byter plats på två intilliggande noder i en enkel länkad lista */
void swap_nodes(List* head_ref,  Node* prev,  Node* curr);

/* Sorterar en enkel länkad lista med Bubble Sort (byter noder, inte data) */
void bubble_sort(List* head_ref);

/* Sorterar en array med Merge Sort */
void merge_sort(int* arr, int left, int right);

/* Sorterar en array med Quick Sort */
void quick_sort(int* arr, int start, int end);

/* Hjälpfunktion för att dela upp arrayen i Quick Sort */
int partition(int* arr, int start, int end);

List create_random_list(int size, int min, int max);

#endif

