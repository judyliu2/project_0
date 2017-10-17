#include <stdio.h>
#include <stdlib.h>

#include <time.h>


struct song_node{ 
  char *name;
  char *artist;
  struct song_node *next;
};

struct song_node *table[26];
void print_list(struct song_node* node);

struct song_node * insert_front(struct song_node *front_song, char *new_name, char *new_artist);

struct song_node * insert_order(struct song_node *front_song, char *new_name, char *new_artist);

struct song_node * find_sname(struct song_node *front_song, char *new_name);

struct song_node * find_aname(struct song_node *front_song, char *new_name);

struct song_node * random_song(struct song_node *front_song);

struct song_node * remove_node(struct song_node *front_song, char *s_name, char *s_artist);

struct song_node * freelist(struct song_node *front_song);



void print_list(struct song_node* node){
  while(node){
    printf(" %s \t:  %s\t | \t", node->artist, node-> name);
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
  struct song_node *new_song;
  struct song_node *old_head = front_song;
  new_song ->name = new_name;
  new_song ->artist = new_artist;
  while(old_head->next != NULL){
    struct song_node *temp = old_head ->next;
    
    if (((new_song->name) > (old_head->name)) && ((new_song->name) < (temp-> name))){
     
      old_head-> next = new_song;
      new_song-> next = temp;
      
    }
    front_song= front_song->next;
  }
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
  while (random > 0){
    temp = temp->next;
    random =- 1;
  }
  return front_song;
}

struct song_node * remove_node(struct song_node *front_song, char *s_name, char *s_artist){
  struct song_node * old_head;
  while (old_head){                                       //1 song in list
    if (old_head->next == NULL){
      if ((old_head->name == s_name) && (old_head->artist == s_artist)){
	free(old_head);
      }
      
    }
    
    else{
      struct song_node *temp = old_head->next;
      if (temp->next != NULL){                             // at least 3 songs
	struct song_node *temp2 = temp->next;
	if ((temp->name == s_name) && (temp->artist == s_artist)){
	  old_head->next = temp2;
	  free(temp);
	}
      }
      else{
	if ((temp->name == s_name) && (temp->artist == s_artist)){ //freed song is at the end
	  free(temp);
	  old_head->next = NULL;
	}
      }

    }
    old_head = old_head->next;
  }
  
  return front_song;
}

struct song_node * freelist(struct song_node *front_song){
  struct song_node *old_head = front_song;
  while(old_head->next != NULL){
    struct song_node *temp = old_head->next;
    free(old_head);
    old_head = temp;
  }
  free(old_head);
  return front_song;
}


int main(){
  struct song_node *table[26];
  printf("Testing print_library:\n");
  printf("=================================\n");

  printf("Testing print_letter:\n");
  printf("=================================\n");

  printf("Testing find:\n");
  
  printf("Testing find artist:\n");

  printf("Testing find:\n");

  printf("Testing remove_song:\n");

  printf("Testing clear_library:\n");

  printf("Library after clear:\n");
  return 0;
}
