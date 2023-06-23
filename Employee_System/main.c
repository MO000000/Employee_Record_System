
#include "Emplyee_Record_System.h"

int main() {
  uint32 UserChoice = 0;

  printf("-> Hello to Employee Record System List \n");
  while (1) {
    printf("\n");
    printf("===================================\n");
    printf("-> 1) Add New Employee Data \n");
    printf("-> 2) Delete an Employee Data \n");
    printf("-> 3) Modify an Employee Data \n");
    printf("-> 4) View an Employee Data \n");
    printf("-> 5) View All Employees Data\n");
    printf("-> 6) Exit List \n");
    printf("====================================\n");

    printf("\n");
    printf("UserChoice : ");
    scanf("%d", &UserChoice);

    switch (UserChoice) {
    case 1:
      Add_New_Employee_Data();
      break;
    case 2:
      Delete_Employee_Data();
      break;
    case 3:
      Modify_Employee_Data();
      break;
    case 4:
      View_Employee_Data();
      break;
    case 5:
      View_All_Employees_Data();
      break;
    case 6:
      Exit_List();
      exit(1);
      break;
    default:
      printf("User Choice out of Range !!\n");
    }
  }
  return 0;
}
