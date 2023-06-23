/*
 * File:  Employee_Record_System.c
 * Author: Mohamed_Hossam El-Din_Heikl
 * Created on June 18, 2023, 10:48 PM
 * NTI_Final_Project
 */

#include "Emplyee_Record_System.h"

/*============== Software Interfaces Definitions =================*/

struct employee *List_Head = NULL;
uint32 Employee_Count = 0;

/**
 * @brief Function to Add_New_Employee_Data to List.
 */
void Add_New_Employee_Data() {
  system("cls");
  uint8 Choise = 'N';
  struct employee *New_Emp = (struct employee *)malloc(sizeof(struct employee));
  struct employee *Last_Emp = (struct employee *)malloc(sizeof(struct employee));
  New_Emp->E_Data = (Emp_t *)malloc(sizeof(Emp_t));

    if (NULL != New_Emp) {
      printf("Enter New Employee Name:\n");
      scanf("%s", New_Emp->E_Data->Name);
      printf("Enter New Employee Age:\n");
      scanf("%d", &New_Emp->E_Data->Age);
      printf("Enter New Employee Salary:\n");
      scanf("%f", &New_Emp->E_Data->Salary);
      printf("Enter New Employee ID:\n");
      scanf("%d", &New_Emp->E_Data->ID);
      printf("Enter New Employee Title:\n");
      scanf("%s", New_Emp->E_Data->Title);
               New_Emp->Next = NULL;

            if (NULL == List_Head) {
              List_Head = New_Emp;
            } else {
              Last_Emp = List_Head;
              while (NULL != Last_Emp->Next) {
                Last_Emp = Last_Emp->Next;
              }
              Last_Emp->Next = New_Emp;
              Employee_Count++;
            }
            printf("//========= Employee added successfully! ==========//\n");
          }

  printf("//======================================================//\n");
  printf("Do you want to Add Another Employee Data (Y or N)\n");
  fflush(stdin);
  scanf("%c", &Choise);
  if ((Choise == 'y') || (Choise == 'Y')) {
    return;
  } 
  else {
    exit(EXIT_SUCCESS);
  }
}


/**
 * @brief Function to Delete an Employee Data from List.
 * @param  id: employee id to be deleted
 */
void Delete_Employee_Data(uint32 id) {
  system("cls");
  printf("Enter the ID of the Employee you want to delete\n");
  scanf("%d", &id);
  struct employee *Temp_Emp = List_Head;
  struct employee *Previous_Emp = NULL;
  while (Temp_Emp != NULL) {
    if (Temp_Emp->E_Data->ID == id) {
      if (Previous_Emp == NULL) {
        List_Head = Temp_Emp->Next;
      } 
      else {
        Previous_Emp->Next = Temp_Emp->Next;
      }
      free(Temp_Emp);
      Employee_Count--;
      printf("//====== Employee Deleted Successfully! =========//\n");
      return;
    }
    Previous_Emp = Temp_Emp;
    Temp_Emp = Temp_Emp->Next;
  }
  printf("Employee with ID %d not found.\n", id);
}

/**
 * @brief Function to Modify_Employee_Data on List.
 * @param  id: employee id to be modified
 */
void Modify_Employee_Data(uint32 id) {
  system("cls");
  printf("Enter the ID of the Employee you want to Modify\n");
  scanf("%d", &id);
  struct employee *Temp_Emp = List_Head;
  while (Temp_Emp != NULL) {
    if (id == Temp_Emp->E_Data->ID) {
      printf("Enter new Name for Employee with ID %d: ", id);
      scanf("%s", Temp_Emp->E_Data->Name);
      printf("Enter new Age for Employee with ID %d:", id);
      scanf("%d", &Temp_Emp->E_Data->Age);
      printf("Enter new Salary for Employee with ID %d: ", id);
      scanf("%f", &Temp_Emp->E_Data->Salary);
      printf("Enter new Title for Employee with ID %d:", id);
      scanf("%s", Temp_Emp->E_Data->Title);
      printf("Enter new ID for Employee with ID %d:", id);
      scanf("%d", &Temp_Emp->E_Data->ID);
      printf("//========== Employee modified successfully! ===========//\n");
      return;
    }
    Temp_Emp = Temp_Emp->Next;
  }
  printf("Employee with ID %d not found.\n", id);
}

/**
 * @brief Function to View_an_Employee_Data on the List.
 * @param  id: employee id to be viewed
 */
void View_Employee_Data(uint32 id) {
  system("cls");
  printf("Enter the ID of the Employee you want to view\n");
  scanf("%d", &id);
  struct employee *Temp_Emp = List_Head;
  printf("Name\tAge\tSalary\tTitle\tID\n");
  printf("//==============================================//\n");
  while (Temp_Emp != NULL) {
    if (id == Temp_Emp->E_Data->ID) {
      printf("%s\t%d\t%f\t%s\t%d\n", Temp_Emp->E_Data->Name,
             Temp_Emp->E_Data->Age, Temp_Emp->E_Data->Salary,
             Temp_Emp->E_Data->Title, Temp_Emp->E_Data->ID);
    }
    Temp_Emp = Temp_Emp->Next;
  }
  printf("Employee with ID %d not found.\n", id);
}

/**
 * @brief Function to View_All_Employees_Data on the List.
 */
void View_All_Employees_Data() {
  system("cls");
  struct employee *Temp_Emp = List_Head;
  printf("Name\tAge\tSalary\tTitle\tID\n");
  printf("//==============================================//\n");
  if (NULL == Temp_Emp) {
    printf("Employees List is Empty..!, NO Data to view\n");
  } 
  else {
    while (Temp_Emp != NULL) {
      printf("%s\t%d\t%f\t%s\t%d\n", Temp_Emp->E_Data->Name,
             Temp_Emp->E_Data->Age, Temp_Emp->E_Data->Salary,
             Temp_Emp->E_Data->Title, Temp_Emp->E_Data->ID);

      Temp_Emp = Temp_Emp->Next;
    }
    if (NULL == Temp_Emp) {
      printf("NULL\n");
    }
  }
  printf("//================================================//\n");
  printf("****** Total Employees ******** : %d\n", Employee_Count);
}

/**
 * @brief Function to Exit the Employee List.
 */
void Exit_List(struct employee *Emp) {
  system("cls");
  printf("\nExiting...\n");
  free(Emp);
}
