#include <stdlib.h>
#include <stdio.h>

struct song_node{ 
  char *name;
  char *artist;
  struct song_node *next;
};


void print_node(struct song_node* node){
  printf("Name: %s, Artist:%s |",node->name,node->artist);
}

void print_list(struct song_node* node){
  
  while(node){
    print_node(node);
    node = node->next;
  }

}

struct song_node * insert_front(struct song_node *front_song, char *new_name, char *new_artist){
  struct song_node *new_song = (struct song_node*) malloc (sizeof(struct song_node));
  new_song -> next = front_song;
  new_song -> name = new_name;
  new_song -> artist = new_artist;
  return new_song;
}

struct song_node * insert_order(struct song_node *front_song, char *new_name, char *new_artist){

  struct song_node *new_song = (struct song_node*) malloc(sizeof(struct song_node));
  new_song->name = new_name;
  new_song->artist = new_artist;

  if (new_name < front_song-> name){
    new_song->next = front_song;
    return new_song;
  }
  
  struct song_node *temp = NULL;
  temp = front_song;
  while (temp->next != NULL && new_name > temp->name){
    temp = temp-> next;
  }
  
  new_song->next = temp->next;
  temp->next = new_song;


  
  return front_song;
}

struct song_node * find_sname(struct song_node *front_song, char *s_name){
  struct song_node *temp = front_song;
  while (temp){
    if(temp->name == s_name){
      return temp;
    }
    temp= temp->next;
  }
  return NULL;
}

struct song_node * find_aname(struct song_node *front_song, char *s_artist){
  struct song_node *temp = front_song;
  while (temp){
    if(temp->artist == s_artist){
      return temp;
    }
    temp= temp->next;
  }
  return NULL;
}

struct song_node * random_song(struct song_node *front_song){
  struct song_node *temp = front_song;
  int counter = 0;
  while(temp){
    temp = temp->next;
    counter++;
  }
  
  srand(time(NULL));
  int random =  rand() % (counter + 1 - 0) + 0;
  temp = front_song;
  while (random > -1){
    temp = temp->next;
    random =- 1;
  }
  return temp;
}

void remove_node(struct song_node *front_song, char *s_name, char *s_artist){
  if (front_song == NULL){
    return;
  }
  struct song_node *temp = front_song;
  struct song_node *holder= front_song;
  if (temp->name == s_name && temp->artist == s_artist){
    front_song = temp->next;
    free(temp);
    return;
  }
  while (temp->next != NULL && temp-> next-> name != s_name && temp-> next-> artist != s_artist){
    temp = temp-> next;
  }
  if (temp->next == NULL){
    printf("given song has not been found\n");
    return;
  }
 
  holder = temp->next->next;
  free(temp->next);
  temp->next = holder;

}

struct song_node * freelist(struct song_node *front_song){

  if (!front_song){
    return 0;
  }
  freelist(front_song->next);
  free(front_song);
  return 0;
  
 
}
struct song_node * add_lib(struct song_node* table[26], char*s_name, char* s_artist){
  int i = (int) (s_name[0]-97);
  return insert_order(table[i], s_name, s_artist);

}

struct song_node * find_song(struct song_node* table[26], char * s_name, char * s_artist){
  int i ;
  for (i = 0; i< 26; i ++){
    struct song_node* temp = (struct song_node* )table[i];
    while (temp){
      if(temp->name == s_name && temp->artist == s_artist){
	return temp;
      }
      temp= temp->next;
    }
  }
  return NULL;
}


struct song_node * find_artist(struct song_node* table[26],char* artist){
  int i ;
  for (i = 0; i< 26; i ++){
    struct song_node* temp = table[i];
    while (temp){
      return find_aname( temp, artist);
    }
      
  }
}


void print_songs( struct song_node* table[26], char letter){
  print_list(table [(int)letter - 97]);

}

void print_artist(struct song_node* table[26], char * artist){
  int i;
  for (i = 0; i < 26; i++){
    struct song_node* temp = (struct song_node*) table[i];
    
    while (temp){

      if (temp->artist == artist){
	print_node(temp);
      }
      temp = temp->next;
    }
  }
}

void print_lib(struct song_node* table[26]){
  int i;

  for (i = 0; i< 26; i ++){
    printf("\n %c list:\n", (char)i+97 );
    struct song_node* temp = table[i];
    while (temp->next != NULL){
 
      print_list(temp);
      temp=temp->next;
    }
  }
  
}


void shuffle(struct song_node* table[26]){
  int len = 5;
  while (len>0){
    int random_letter = rand() %26;
    if (table[random_letter]){
      print_node(random_song(table[random_letter]));
      len -= 1;
    }
  }
  return;
}
  



void delete_song(struct song_node* table[26], char*s_name, char* s_artist){
   int i ;
  for (i = 0; i< 26; i ++){
    struct song_node* temp = (struct song_node*)table[i];
    while (temp->next != NULL){
      remove_node(temp, s_name, s_artist);

      return;
    }
  }
}

void delete_all(struct song_node* table[26]){
  int i;
  for (i = 0; i<26; i++){
    free(table[i]);
  }
}


