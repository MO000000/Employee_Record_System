/*
 * File:  Employee_Record_System.h
 * Author: Mohamed_Hossam El-Din_Heikl
 * Created on June 18, 2023, 10:48 PM
 * NTI_Final_Project
 */


#ifndef EMPLYEE_RECORD_SYSTEM_H
#define EMPLYEE_RECORD_SYSTEM_H

/*=========================== includes ==============================*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

/*==================== Data types Declarations ======================*/

typedef unsigned int uint32;
typedef unsigned short uint16;
typedef unsigned char uint8;

  typedef struct
    {
        uint8 Name[40];
        uint32 Age;
        float Salary;
        uint8 Title[20];
        uint32 ID;
  } Emp_t;

   struct employee{
       Emp_t *E_Data;
       struct employee *Next;
  };

  /*====================== Macro Declarations ==========================*/

  #define  EMP_LIST_SIZE  100

/*================== Macro Functions Declarations =====================*/

/*================== Software Interfaces Declarations =================*/

  void Add_New_Employee_Data();
  void Delete_Employee_Data();
  void Modify_Employee_Data();
  void View_Employee_Data();
  void View_All_Employees_Data();
  void Exit_List();


#endif /* EMPLYEE_RECORD_SYSTEM_H */