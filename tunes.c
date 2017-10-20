#include <stdio.h>
#include <stdlib.h>

#include <time.h>


struct song_node{ 
  char *name;
  char *artist;
  struct song_node *next;
};
void print_node(struct song_node* node);
void print_list(struct song_node* node);

struct song_node * insert_front(struct song_node *front_song, char *new_name, char *new_artist);

struct song_node * insert_order(struct song_node *front_song, char *new_name, char *new_artist);

struct song_node * find_sname(struct song_node *front_song, char *new_name);

struct song_node * find_aname(struct song_node *front_song, char *new_name);

struct song_node * random_song(struct song_node *front_song);

void remove_node(struct song_node *front_song, char *s_name, char *s_artist);

struct song_node * freelist(struct song_node *front_song);

struct song_node * find_song(struct song_node* table[26],char * s_name, char * s_artist);

struct song_node * find_artist(struct song_node* table[26],char* artist);


struct song_node * add_lib(struct song_node* table[26], char*s_name, char* s_artist);

void print_songs( struct song_node* table[26], char letter);

void print_artist(struct song_node* table[26], char * artist);

void print_lib(struct song_node* table[26]);

void shuffle(struct song_node* table[26]);

void delete_song(struct song_node* table[26], char* s_name, char* s_artist);

void delete_all(struct song_node* table[26]);


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
  int len = 3;
  while (len>0){
    int random_letter = rand() %26;
    if (table[random_letter]){
      print_node(random_song(table[random_letter]));
      len -= 3;
    }
  }
}
  
  /*
  //while randomly chooses a random numbr of songs
  int random_len = 5;
  while(random_len){
    srand(time(NULL));
    int random_letter = rand() % (25 + 1 - 0) + 0;
    if (table[random_letter]){
      struct song_node *r_song = random_song(table[random_letter]);
      print_node(r_song);
    }
    random_len = random_len -1;
  }
  return;
  */



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


int main(){
  struct song_node *test = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test1 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test2 = (struct song_node*) malloc (sizeof (struct song_node));
  //test-> name = "apple";
    // test-> artist = "bee";

    struct song_node *table[26] =
      {test2,test1,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test};
    /*
  printf("Testing Linked List Functions:\n");

  test-> artist = "imagine dragons";
  printf("Testing print_list:\n");
  print_list(test);
  printf("\n");
  printf("=================================\n");
  
  printf("Testing insert_front:\n");
  struct song_node *p = insert_front(test, "xo", "eden");
  print_list(p);
  printf("\n");
  //freelist(test);
  //freelist(p);
  printf("=================================\n");
  
  printf("Testing insert_order:\n");
  struct song_node *o = insert_order(test, "xo", "eden");
  print_list(o);
  printf("\n");
  struct song_node *q = insert_order(o, "zzz", "somebody");
  print_list(q);
  printf("\n");

  printf("=================================\n");
  
  printf("Testing:find_sname\n");
  printf("Location of \"not today \": %p \n", find_sname(q,"not today"));
  
  printf("=================================\n");
  
  printf("Testing:find_aname\n");
  printf("Location of \"imagine dragons \": %p \n", find_aname(q,"imagine dragons"));
  
  printf("=================================\n");
   
  printf("Testing: random_song(): Should return a pointer to a song \n");
  print_list(random_song(o));
  printf("\n");

  printf("=================================\n");
   
  printf("Testing:remove_node\n");
  remove_node(o, "xo" , "eden");
  print_list(o);
  printf("\n");

  printf("=================================\n");
   
  printf("Testing:remove_node\n");
  remove_node(o, "not today" , "imagine dragons");
  print_list(o);
  printf("\n");
  printf("\n");
  printf("=================================\n");
    */
  printf("Testing Music Library functions:\n");

  printf("=================================\n");
  
  printf("Testing print_lib:\n");
  printf("=================================\n");
  print_lib(table);
  printf("\n");
  printf("=================================\n");
  
  printf("Testing add_lib:\n");
  printf("=================================\n");
  add_lib(table, "atlantis", "seafret");
  add_lib(table, "banana", "fruits");
   print_lib(table);
   printf("\n");

  printf("Testing print_letter:\n");
  printf("=================================\n");

  printf("Testing find_song:\n");
  printf("atlantic, seafret is at: %p",find_song(table, "atlantis", "seafret"));
  printf("\n");

  printf("=================================\n");
  printf("Testing find artist:\n");

  printf("seafret is at: %p", find_artist(table, "seafret"));
  printf("\n=================================\n");

  printf("Testing print_artist:\n");
   print_artist(table, "fruit");
  printf("=================================\n");
  

  printf("Testing print_songs:\n");
  print_songs(table, 'a');
  printf("\n=================================\n");

  printf("Testing delete_song:\n");
  delete_song(table,"atlantis", "seafret");
  print_lib(table);
  printf("=================================\n");
  //shuffle(table);

  printf("Testing clear_library:\n");
  //delete_all(table);
  
  printf("=================================\n"); 
  printf("Library after clear:\n");
  //print_lib(table);
  printf("=================================\n");
  return 0;
}
