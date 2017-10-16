typedef struct song_node{ 
  char name[256];
  char artist[256];
  struct song_node *next;
} song_node;

void print_list(struct song_node*);

struct song_node * insert_front(struct song_node *, char *);

struct song_node * insert_order(struct song_node *, char *);

struct song_node * find_sname(char *);

struct song_node * find_aname(char *);

struct song_node * remove_node(struct song_node *);

struct song_node * freelist(struct song_node *);

