#include <stdio.h>
#include <stdlib.h>
#include "headers.h"
#include <time.h>

int main(){
  
  struct song_node *test = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test1 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test2 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test3 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test4 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test5 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test6 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test7 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test8 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test9 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test10 = (struct song_node*) malloc (sizeof (struct song_node));
   struct song_node *test11 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test12 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test13 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test14 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test15 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test16 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test17 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test18 = (struct song_node*) malloc (sizeof (struct song_node));
   struct song_node *test19 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test20 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test21 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test22 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test23 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test24 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test25 = (struct song_node*) malloc (sizeof (struct song_node));
  struct song_node *test26 = (struct song_node*) malloc (sizeof (struct song_node));
  


  struct song_node *table[26] =
    {test1,test2,test3,test4,test5,test6,test7,test8,test9,test10,test11,test12,test13,test14,test15,test16,test17,test18,test19,test20,test21,test22,test23,test24,test25,test26};
  
  printf("Testing Linked List Functions:\n");
  test->name = "not today";
  test-> artist = "imagine dragons";
  printf("Testing print_list:\n");
  print_list(test);
  printf("\n");
  printf("=================================\n");
  
  printf("Testing insert_front:\n");
  struct song_node *p = insert_front(test, "xo", "eden");
  print_list(p);
  printf("\n");  //freelist(test);
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
  add_lib(table, "ccc", "pet");
  
  add_lib(table, "dog", "pet");
  
  add_lib(table, "elephant", "pet");
  add_lib(table, "fish", "pet");
  add_lib(table, "gold", "rock");
  add_lib(table, "alphabet", "ABCS");
  add_lib(table, "hop", "glasshopper");
  add_lib(table, "ice cream", "food");
  add_lib(table, "jude", "beatles");
  add_lib(table, "kangaroo", "roo");
  add_lib(table, "let it all go", "birdy");
  add_lib(table, "moose","pet");
  add_lib(table, "not today","imagine dragons");
  add_lib(table, "one more light","linkin park");
  add_lib(table, "puppy", "pet");
  add_lib(table, "quack", "duck");
  add_lib(table, "radioactive", "imagine dragons");
  add_lib(table, "shots", "imagine dragons");
  add_lib(table, "teletubbies", "pbs");
  add_lib(table, "under","armour");
  add_lib(table, "v for vandetta", "movie");
  add_lib(table, "without you","oh wonder");
  add_lib(table, "xxx","y");
  add_lib(table, "yuck","homework");
  add_lib(table, "zebra", "horse");
  
  
   print_lib(table);
   printf("\n");
   
  printf("Testing print_letter:\n");
  printf("=================================\n");

  printf("Testing find_song:\n");
  printf("finding atlantis by seafret\n");
  printf("atlantic, seafret is at: %p",find_song(table, "atlantis", "seafret"));
  printf("\n");

  printf("=================================\n");
  printf("Testing find artist:\n");
  printf("finding seafret");
  printf("seafret is at: %p", find_artist(table, "seafret"));
  printf("\n=================================\n");

  printf("Testing print_artist:\n");
  printf("printing songs by ABCS\n");
   print_artist(table, "ABCS");
  printf("\n=================================\n");
  

  printf("Testing print_songs:\n");
  printf("printing songs that start with 'a'\n");
  print_songs(table, 'a');
  printf("\n=================================\n");

  printf("Testing delete_song:\n");
  printf("deleting atlantis by seafret");
  delete_song(table,"atlantis", "seafret");
  print_lib(table);
  printf("\n");
  printf("=================================\n");
   
  printf("Testing shuffle\n");
  shuffle(table);

  printf("\n=================================\n");

  printf("Testing clear_library:\n");
   
  delete_all(table);
  
  printf("=================================\n"); 
  printf("Library after clear:\n");
  print_lib(table);
  printf("\n=================================\n");
  
  return 0;
  }
