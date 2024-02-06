#ifndef SRC_DOOR_STRUCT_H
#define SRC_DOOR_STRUCT_H

struct door {
	int id;
	int status;
};

void initialize_doors(struct door* doors);
void sorting(struct door* doors);
void status_door(struct door* doors);
void output(struct door* doors);

#endif // SRC_DOOR_STRUCT_H 