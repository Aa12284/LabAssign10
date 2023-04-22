#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 26

struct Trie {
	struct Trie* letters[SIZE];
	int ct;
};

void insert(struct Trie **ppTrie, char *word) {
	struct Trie* current = *ppTrie;
	
	for (int i = 0; word[i] != '\0'; i++) {
		int ind = word[i] - 'a';
		
	
	if (current->letters[ind] = NULL) {
		
		current->letters[ind] = (struct Trie*)malloc(sizeof(struct Trie));
		
		for (int b = 0; b < SIZE; b++) {
			current->letters[ind]->letters[b] = NULL;
		}
		current->letters[ind]->ct = 0;
	}
	
	current = current->letters[ind];
} 

current->ct++;
}

int numberOfOccurances(struct Trie *pTrie, char *word) {
	struct Trie* current = pTrie;
	
	for (int i = 0; word[i] != '\0'; i++) {
		int ind = word[i] - 'a';
		
		if (current->letters[ind] == NULL) {
			return 0;
		}
		
		current = current->letters[ind];
	}
	
	return current->ct;
}
struct Trie *deallocateTrie(struct Trie *pTrie) {
	if (pTrie = NULL) {
		return NULL;
	}
	
	for (int i = 0; i < SIZE; i++) {
		if (pTrie->letters[i] != NULL) {
			
			deallocateTrie(pTrie->letters[i]);
		}
	} return NULL;
}

int main(void)
{
      //read the number of the words in the dictionary
      // parse line  by line, and insert each word to the trie data structure
      struct Trie* trie = (struct Trie*)malloc(sizeof(struct Trie));
      printf("Please type a word: ");
      for (int i = 0; i < SIZE; i++) {
      	trie->letters[i] = NULL;
	  }
	  
	  trie->ct = 0;
	  
	  int n;
	  scanf("%d", &n);
	  
	  
	  char word[100];
	  
	  for (int i = 0; i < n; i++) {
	  	scanf("%s", word);
	  	
	  	insert(&trie, word);
	  }
	  
      
      // search for each test word and print the number of occurrences
    char* pWords[] = {"notaword", "ucf", "no", "note", "corg"};
    for (int i = 0; i < 5; i++) {
        printf("\t%s : %d\n", pWords[i], numberOfOccurances(trie, pWords[i]));
    }

    // deallocate the trie data structure
    trie = deallocateTrie(trie);
    if (trie != NULL) {
        printf("There is an error in this program\n");
    }

    return 0;
}
