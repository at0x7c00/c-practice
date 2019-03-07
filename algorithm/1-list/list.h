typedef Node_ptr List;
typedef Node_ptr Position;

List create_list();
Position insert(List list,Position position,element_type value);
void print_list(List list);
int is_empty(List list);
int is_last(Position p);
Position find(element_type x,List list);
int list_len(List list);
void delete(List list,element_type value);
