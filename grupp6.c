#include "grupp6.h"
#include <string.h>
#include <stdlib.h>
#include <nrf_gpio.h>
#include <assert.h>
#include <stdio.h>   // för sprintf
#include <time.h>   // För srand och time


//Returnera en tom lista - funktionen är färdig

List create_empty_list(void)
{
    return NULL;
}

/*   c Filen från laboration 2
//Här skapas nya noder. Denna funktion är den enda som ska använda malloc.
//Denna funktion ska i sin tur bara kallas av add_first och add_last.
//Notera att den är static och inte finns med i interfacet.
*/
static Node * create_list_node(const Data data)
{
	//glöm inte att kolla så att malloc inte returnerade NULL

	//Node * omvandlar pekaren som malloc ger till Node*
	Node *new_node = (Node *)malloc(sizeof(Node)); // Vi allokerar plats i minnet för en ny nod
	
	if (new_node == NULL){ //kontrollera om malloc inte kunde allokera minne, då bryter vi direkt.
		return NULL;
	}

	new_node->data = data; //här sparar vi det inskickade värdet i nodens data fält.

	new_node->next = NULL;

	return new_node; //returnera perkaren till den nya noden så att andra funktioner har tillgång till den.
}
/*
//Är listan tom?
//Returnerar 1 om listan är tom, annars 0
int is_empty(const List list)
{
	if (list == NULL)
        return 1;
    else
        return 0;
	//Om listan är tom, returnera 1, anars returnera 0.
} 
*/
//Lägg till en nod först i listan
void add_first(List *list, const Data data)
{
	Node *new_node = create_list_node(data); //Skapa en ny nod
	if (new_node == NULL){
		return; //Gör ingenting om noden är tom
	}

	new_node->next = *list; // Nya noden pekar på nuvarande första nod
	*list = new_node; // listan pekar nu på nya noden
}
/*
//lägg till nod sist i listan
void add_last(List *list, const Data data)
{
	Node *new_node = create_list_node(data);

	if (new_node == NULL){
		return;
	}

	if (*list == NULL){
		*list = new_node;
	}
	else{
		// Vi vill hitta sista noden i listan next == NULL

		Node *current = *list; //Skapa ny pekare som vi använder för att gå igenom listan, till *list
		
		while (current->next != NULL){ // Så länge det inte är tomt efter current
			current = current->next; //Gå till nästa nd
		}
		current->next = new_node; // Efter att while-loopen avbryts, sätt in datan i slutet
	}
}
*/ 
/*
//Ta bort första noden i listan 
//precondition: listan är inte tom (testa med assert)
void remove_first(List *list)
{
	assert(*list != NULL); //Se till att listan inte är tom, annars stoppa programmet

	Node *temp = *list; //Spara första noden i en annan pekare
	*list = temp->next; // Flytta hela headen (listan) till nästa nod och hoppar förbi första
	free(temp); //Frigör minnet i noden temp
}

//ta bort sista noden i listan
//precondition: listan är inte tom (testa med assert)
void remove_last(List *list)
{
	assert(*list != NULL); 

	if((*list)->next == NULL){ //Om det bara är en element
		free(*list); 
		*list = NULL; //Listan är tom nu
	}
	else{
		Node *current = *list; //skapar ny pekare för att gå igenom listan
		while(current->next->next != NULL){ //Vi letar efter den näst sista noden
		//Så den näst nästa element inte är tom, fortsätt gå igenom listan
			current = current->next;
		}

		free(current->next); //Nu är sista noden tom när current->next->next är NULL
		current->next = NULL; // Nu är sista noden den som var näst sist efter att vi raderade sista
	}
}

//töm listan (ta bort alla noder ur listan)
//postcondition: Listan är tom, *list är NULL
void clear_list(List *list)
{
	//alla noder ska frigöras

	if (*list == NULL)
		return;

	Node *temp = *list;

	// Flytta listpekaren till nästa nod
    // Detta gör att nästa rekursiva anrop kommer börja på nästa nod i listan
	*list = temp->next;

	// Anropa samma funktion igen med den nya listpekaren (nästa nod)
    // Detta fortsätter tills vi når slutet av listan (där *list == NULL)
	clear_list(list);

	// Då frigör vi den nod vi sparade tidigare
	free(temp);
	
}
*/
//Skriv ut listan genom UART
void print_list(const List list)
{
	char buffer[20];

    if (list == NULL)
        return;

    sprintf(buffer, "%d ", list->data);   // Gör om tal till text
    uart_send_string(buffer);             // Skicka till Putty via UART
    print_list(list->next);               // Nästa nod (rekursivt)
}
/*
//returnera första datat i listan
//precondition: listan är inte tom (testa med assert)
Data get_first_element(const List list)
{
	assert(list != NULL); // Om listan är tom så bryts det.

	return list->data; //returnera värdet på första noden bara
}

//returnera sista datat i listan. 
//precondition: listan är inte tom (testa med assert)
Data get_last_element(const List list)
{
	assert(list != NULL);

	Node *current = list;
	while (current->next != NULL){
		current = current->next;
	}
	return current->data;
}

//Returnera hur många noder som finns i listan
int number_of_nodes(const List list)
{
	if(list == NULL)
		return 0;

	return 1 + number_of_nodes(list->next); //Den räknar 1 + antal element med NULL som stänger funktionen
}

//Sök efter data i listan, returnera 1 om datat finns, annars 0.
int search(const List list, const Data data)
{
	if(list == NULL)
		return 0;

	if(list->data == data)
		return 1;

	return search(list->next, data); //Kolla på nästa nod
}

//Ta bort data ur listan (första förekomsten), returnera 0 om datat inte finns, annars 1
int remove_element(List *list, const Data data)
{
	if(*list == NULL)
		return 0;

	if((*list)->data == data){
		Node *temp = *list;
		*list = temp->next;
		free(temp);
		return 1;
	}

	Node *current = *list;

	while (current->next != NULL){
		if(current->next->data == data){
			Node *temp = current->next;
			current->next = temp->next;
			free(temp);
			return 1;
		}
		current = current->next;
	}

	return 0;
}
*/



/*Det är helt tillåtet att lägga till egna hjälpfunktioner men de befintliga funktionerna ska implementeras enligt instruktionerna*/

/* Statiska hjälpfunktioner används av andra funktioner i trädet och ska inte ligga i interfacet (användaren behöver inte känna till dessa) */

// Skapar en ny trädnod med data
static struct treeNode* create_tree_node(int data)
{
	struct treeNode* new_node = malloc(sizeof(struct treeNode)); // Allokerar minne för en ny nod
    if (new_node == NULL) 
    return NULL; 
    new_node->data = data;   // Sätt in det givna värdet i noden
    new_node->left = NULL;   // Vänsterbarn är tomt
    new_node->right = NULL;  // Högerbarn är också tomt
    return new_node;         // Returnerar pekare till nya noden
}

// Hjälpfunktion som skriver ut trädet i sorterad ordning till array 
static void write_inorder(const BSTree tree, int* arr, int* index)
{
    if (tree == NULL)
     return;               // Avbryt om trädet är tomt
    write_inorder(tree->left, arr, index);  // Gå först till vänsterbarn
    arr[(*index)++] = tree->data;           // Spara värdet i arrayen och öka index
    write_inorder(tree->right, arr, index); // Gå sedan till högerbarn
}

/* Returnerar en dynamiskt allokerad array som innehåller trädets data sorterat */
static int* write_sorted_to_array(const BSTree tree)
{
	int size = number_of_nodes(tree);       // Räkna hur många noder trädet har
    int* arr = malloc(sizeof(int) * size);   // Skapa array i heapen
    int index = 0;                      // Startindex
    write_inorder(tree, arr, &index);    // Fyll arrayen med data från trädet (inorder)
    return arr;                           // Returnera arrayen
}

// Hjälpfunktion som bygger ett träd från en sorterad array
static void build_tree_from_array(BSTree* tree, const int* arr, int start, int end)
{
    if (start > end) 
    return;   

    int mid = (start + end) / 2;    // Hitta mitten av delområdet
    insert_sorted(tree, arr[mid]);   // Sätt in mittenvärdet som nod

    build_tree_from_array(tree, arr, start, mid - 1); // Bygg vänster delträd
    build_tree_from_array(tree, arr, mid + 1, end);   // Bygg höger delträd
}

/* Bygger upp ett sorterat, balanserat träd från en sorterad array */
static void build_tree_sorted_from_array(BSTree* tree, const int arr[], int size)
{
	build_tree_from_array(tree, arr, 0, size - 1);  // Starta bygget från hela arrayen
}

/* Skapar ett tomt träd - denna funktion är färdig */
BSTree create_empty_tree(void)
{
	return NULL;    // Tomt träd representeras med NULL
}

/* Returnerar 1 ifall trädet är tomt, 0 annars */
int is_empty(const BSTree tree)
{
	return (tree == NULL);  // Returnerar 1 om trädet är tomt
}

/* Sätter in data sorterat i *tree */
void insert_sorted(BSTree* tree, int data)
{
	if (*tree == NULL)   // Om trädet är tomt på denna plats
    {
        *tree = create_tree_node(data);  // Skapa en ny nod
    }
    else if (data < (*tree)->data) // Om nya värdet är mindre än nuvarande nod
    {
        insert_sorted(&(*tree)->left, data); // Gå vänster
    }
    else if (data > (*tree)->data)   // Om nya värdet är större
    {
        insert_sorted(&(*tree)->right, data); // Gå höger
    }
    // Om värdet redan finns: gör ingenting (dubletter tillåts ej)
}

int is_sorted_array(const int* arr, int size)
{
    for (int i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return 0;
        }
    }
    return 1;
}

// Denna använder array-funktionen för att jobba med ett träd
int is_sorted(const BSTree tree)
{
    int size = number_of_nodes(tree);
    int* arr = write_sorted_to_array(tree);
    int result = is_sorted_array(arr, size);
    free(arr);
    return result;
}

/* Utskriftsfunktioner – preorder */
void print_preorder(const BSTree tree)
{
    char buffer[20];

    if (tree == NULL) 
        return;

    // 1. Skriv ut roten först
    sprintf(buffer, "%d ", tree->data);
    uart_send_string(buffer);

    // 2. Sedan vänsterbarn
    print_preorder(tree->left);

    // 3. Sedan högerbarn
    print_preorder(tree->right);
}

/* Skriver ut trädet i inorder via UART */
void print_inorder(const BSTree tree)
{
    char buffer[20];

    if (tree == NULL)
        return;

    print_inorder(tree->left);  // Vänster först

    sprintf(buffer, "%d ", tree->data);  // Gör om siffran till text
    uart_send_string(buffer);  // Skicka till Putty via UART

    print_inorder(tree->right);  // Höger sist
}

/* Postorder: vänster → höger → rot */
void print_postorder(const BSTree tree)
{
	char buffer[20];

    if (tree == NULL)
        return;

    // 1. Vänster barn först
    print_postorder(tree->left);

    // 2. Sedan höger barn
    print_postorder(tree->right);

    // 3. Skriv ut roten sist
    sprintf(buffer, "%d ", tree->data);
    uart_send_string(buffer);
}

/* Returnerar 1 om 'data' finns i tree, 0 annars */
int find(const BSTree tree, int data)
{
	if (tree == NULL) 
    return 0;     
    if (data == tree->data) return 1; // Hittade
    if (data < tree->data) return find(tree->left, data);  // Sök vänster
    return find(tree->right, data);   // Sök höger
}

/* Tar bort 'data' från trädet om det finns */
void remove_element(BSTree* tree, int data)
{
	if (*tree == NULL) return;   // Avbryt om trädet är tomt

    if (data < (*tree)->data)
    {
        remove_element(&(*tree)->left, data); // Sök vänster
    }
    else if (data > (*tree)->data)
    {
        remove_element(&(*tree)->right, data);  // Sök höger
    }
    else // Här finns värdet vi vill ta bort
    {
        struct treeNode* temp = *tree;

        if ((*tree)->left == NULL && (*tree)->right == NULL)
        {
            *tree = NULL;   // Fall 1: löv tas bort
        }
        else if ((*tree)->left == NULL)
        {
            *tree = (*tree)->right; // Fall 2: bara höger barn
        }
        else if ((*tree)->right == NULL)
        {
            *tree = (*tree)->left;   // Fall 2: bara vänster barn
        }
        else
        {
            struct treeNode* successor = (*tree)->right;  // Fall 3: två barn
            while (successor->left != NULL)
                successor = successor->left;

            (*tree)->data = successor->data;  // Ersätt med minsta värdet i höger subträd
            remove_element(&(*tree)->right, successor->data); // Ta bort dubblett där nere
            return;
        }
        free(temp);  // Frigör noden från minnet
    }
}

/* Räknar antal noder i trädet */
int number_of_nodes(const BSTree tree)
{
	if (tree == NULL) return 0;
    return 1 + number_of_nodes(tree->left) + number_of_nodes(tree->right);
}

/* Returnerar trädets maximala djup (längsta vägen till ett löv) */
int depth(const BSTree tree)
{
	if (tree == NULL) return 0;
    int left_depth = depth(tree->left);     // Djupet på vänstersida
    int right_depth = depth(tree->right);   // Djupet på högersida
    return 1 + (left_depth > right_depth ? left_depth : right_depth); // Största + 1
}

/* Returnerar minimidjup (kortaste vägen till ett löv) */
int min_depth(const BSTree tree)
{
	if (tree == NULL) return 0;
    int left = min_depth(tree->left);
    int right = min_depth(tree->right);
    if (left == 0 || right == 0)   // Om ena sidan saknas
        return 1 + left + right;     // Hoppa över NULL-gren
    return 1 + (left < right ? left : right);  // Kortaste sidan + 1
}

/* Balanserar trädet så att djupet blir så litet som möjligt */
void balance_tree(BSTree* tree)
{
	int size = number_of_nodes(*tree);   // Hur många noder finns?
    int* arr = write_sorted_to_array(*tree);  // Gör om till sorterad array
    free_tree(tree);   // Töm gamla trädet
    *tree = NULL;       // Pekaren sätts till NULL
    build_tree_sorted_from_array(tree, arr, size);   // Bygg ett nytt balanserat träd
    free(arr);     // Rensa upp arrayen
}

/* Tömmer hela trädet och frigör allt minne */
void free_tree(BSTree* tree)
{
	if (*tree == NULL) return;   // Om trädet är tomt – gör inget
    free_tree(&(*tree)->left);    // Frigör vänstersida
    free_tree(&(*tree)->right);   // Frigör högersida
    free(*tree);    // Frigör själva noden
    *tree = NULL;    // Sätt pekaren till NULL
}

void fill_random_array(int* arr, int size, int min, int max)
{
    for (int i = 0; i < size; i++) {
        arr[i] = min + rand() % (max - min + 1);
    }
}

/* Fyller ett träd med slumpmässiga heltal mellan min och max */
BSTree create_random_tree(int size, int min, int max)
{
    BSTree tree = create_empty_tree();
    for (int i = 0; i < size; i++) {
        int value = min + rand() % (max - min + 1);
        insert_sorted(&tree, value);
    }
    return tree;
}

List create_random_list(int size, int min, int max)
{
    List tree = create_empty_list();
    for (int i = 0; i < size; i++) {
        int value = min + rand() % (max - min + 1);
        add_first(&tree, value);
    }
    return tree;
}










/* Byter plats på två  noder (curr och curr->right) i en enkel länkad lista */
void swap_nodes(List* head_ref, Node* prev, Node* curr)
{
    Node* next = curr->next;

    if (next == NULL) return; // Inget att byta med

    curr->next = next->next;
    next->next = curr;

    if (prev != NULL)
        prev->next = next;
    else
        *head_ref = next;
}

/* Sorterar en enkel länkad lista med Bubble Sort (byter hela noder, inte data) */
void bubble_sort(List* head_ref)
{
    int swapped;

    if (*head_ref == NULL || (*head_ref)->next == NULL)
        return; // redan sorterad

    do {
        swapped = 0;
        Node* prev = NULL;
        Node* curr = *head_ref;

        while (curr != NULL && curr->next != NULL)
        {
            if (curr->data > curr->next->data)
            {
                swap_nodes(head_ref, prev, curr);
                swapped = 1;

                if (prev == NULL)
                    curr = *head_ref;
                else
                    curr = prev->next;
            }
            else
            {
                prev = curr;
                curr = curr->next;
            }
        }
    } while (swapped);
}


static void merge(int* arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = malloc(n1 * sizeof(int));
    int* R = malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];

    free(L);
    free(R);
}

/* Rekursiv Merge Sort-algoritm */
void merge_sort(int* arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);        // Sortera vänstra halvan
        merge_sort(arr, mid + 1, right);   // Sortera högra halvan

        merge(arr, left, mid, right);      // Slå ihop de två halvorna
    }
}

/* Hjälpfunktion som delar upp arrayen kring ett pivot-element för QUICK_SORT */
int partition(int* arr, int start, int end)
{
    int pivot = arr[end];    // Pivot väljs som sista element
    int i = start - 1;       // Index för mindre element

    for (int j = start; j < end; j++) {
        if (arr[j] > pivot) {
            i++;
            // Byt arr[i] och arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Sätt pivot på rätt plats
    i++;
    int temp = arr[i];
    arr[i] = arr[end];
    arr[end] = temp;

    return i;  // Returnera pivotets slutgiltiga plats
}

/* Quick Sort – sorterar en array rekursivt */
void quick_sort(int* arr, int start, int end)
{
    if (start >= end)
        return;

    int pivot_index = partition(arr, start, end);

    quick_sort(arr, start, pivot_index - 1);   // Sortera vänster del
    quick_sort(arr, pivot_index + 1, end);     // Sortera höger del
}
