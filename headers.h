
struct song_node{ 
  char *name;
  char *artist;
  struct song_node *next;
};
void print_node(struct song_node* );
void print_list(struct song_node* );

struct song_node * insert_front(struct song_node *, char *, char *);

struct song_node * insert_order(struct song_node *, char *, char *);

struct song_node * find_sname(struct song_node *, char *);

struct song_node * find_aname(struct song_node *, char *);

struct song_node * random_song(struct song_node *);

void remove_node(struct song_node *, char *, char *);

struct song_node * freelist(struct song_node *);

struct song_node * find_song(struct song_node* [26],char * , char * );

struct song_node * find_artist(struct song_node* [26],char* );


struct song_node * add_lib(struct song_node* [26], char*, char* );

void print_songs( struct song_node* [26], char );

void print_artist(struct song_node* [26], char * );

void print_lib(struct song_node* [26]);

void shuffle(struct song_node* [26]);

void delete_song(struct song_node* [26], char* , char* );

void delete_all(struct song_node* [26]);
