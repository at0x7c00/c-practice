typedef Node_ptr List;
typedef Node_ptr Position;
int is_empty(List list);
int is_last(Position p);
Position find(element_type x,List list);
void create_list(List *list,element_type value);
void insert(List list,element_type value);
void my_print_list(List list);
int list_len(List list);
