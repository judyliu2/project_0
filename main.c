#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>

int main(){
  struct song_node *test = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test1 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test2 = (struct song_node*) malloc (sizeof (struct song_node));
  //test-> name = "apple";
    // test-> artist = "bee";

    struct song_node *table[26] =
      {test2,test1,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test,test};
    
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
  printf("\n");
  printf("=================================\n");
  printf("Testing shuffle\n");
  shuffle(table);
  printf("\n");

  printf("Testing clear_library:\n");
  //delete_all(table);
  
  printf("=================================\n"); 
  printf("Library after clear:\n");
  //print_lib(table);
  printf("=================================\n");
  return 0;
}
