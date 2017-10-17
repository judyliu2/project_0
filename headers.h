typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node* node);

struct song_node * insert_front(struct song_node *front_song, char *new_name, char new_artist*);

struct song_node * insert_order(struct song_node *front_song, char *new_name, char new_artist*);

struct song_node * find_sname(struct song_node *front_song, char *new_name);

struct song_node * find_aname(struct song_node *front_song, char *new_name);

struct song_node * random_song(struct song_node *front_song);

struct song_node * remove_node(struct song_node *front_song, char *s_name, char *s_artist);

struct song_node * freelist(struct song_node *front_song);

