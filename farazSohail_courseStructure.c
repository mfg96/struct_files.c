//Faraz Sohail
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define size 10
#define row 100
#define col 200


char A[row][col];
int M;
int s;
char *ptrA = &A[row][col];

struct CourseInfo
{
    int courseID;
    char courseName[40];
    char courseCode[10];
    char Term [8];
    int courseSection[3];
};
typedef struct CourseInfo courseInfo;

void displayMenu(); 
void displayScourse(courseInfo num[],int n1 );

courseInfo n[size];
courseInfo C;

void sampleCourseInfo() {
  FILE * fp1 = fopen("courseinfo.csv", "w");
  if (fp1 == NULL) {
    printf("UNable to open file.");
    exit(1);
  } else {
    char * course1 = "Programming,03,60,141,1,30,0,W,2015";
    char * course2 = "Algebra,03,62,102,2,0,0,S,2013";
    char * course3 = "Religion,08,98,938,1,30,90,W ,2015";
    fprintf(fp1, "%s\t%s\t%s", course1, course2, course3);
  }
  fclose(fp1);
}

void loadCourseInfo() {
  char B[200];
  int i = 0;
  char * str;
  char * num1;
  FILE * fp2 = fopen("courseinfo.csv", "r");
  if (fp2 == NULL)
    {
    printf("UNable to open file");
    exit(1);
    }
	else {
    while (fgets(B,199,fp2)) {

		n[i].courseID = i+1;
		strcpy(A[i],B);
		str = strtok(A[i], ",");
    // while (str != NULL) {
        strcpy(n[i].courseName, str);
		printf("*****%s\n",n[i].courseName );
        str = strtok(NULL, ",");
        strcpy(n[i].courseCode, str);
        str = strtok(NULL, ",");
        strcat(n[i].courseCode, str);
		strcat(n[i].courseCode,"-");
        str = strtok(NULL, ",");
        strcat(n[i].courseCode, str);
		printf("*****%s\n",n[i].courseCode );
        str = strtok(NULL, ",");
        num1 = str;
        n[i].courseSection[0] = atoi(num1);
        str = strtok(NULL, ",");
        num1 = str;
        n[i].courseSection[1] = atoi(num1);
        str = strtok(NULL, ",");
        num1 = str;
        n[i].courseSection[2] = atoi(num1);
		printf("*****%d",n[i].courseSection[0]);
        str = strtok(NULL, ",");
        strcpy(n[i].Term, str);
        str = strtok(NULL, ",");
        strcat(n[i].Term, str);
		printf("*****%s\n", n[i].Term);
        //n[i].courseID = i+1;

        i++;
      }
	  fclose(fp2);
	  M=i;
	  printf("I = %d , M = %d",i,M );
	  }}

void displayCourseInfo(courseInfo *n,int o)
	  {
		  printf("ID\tName\t\tCode\t\tTerm\t\tSections\n-------------------------------------------------\n");
		  for (int i = 0;i<o; i++)
		{
			printf("%d  \t%s\t%s\t%s\t",(n[i]).courseID, n[i].courseName,n[i].courseCode,n[i].Term);
            for(int k=0;k<3;k++)
                {
			if (n[i].courseSection[k]!=0)
			{   printf("%d,",(n[i]).courseSection[k]);
               // puts(" ");
			}
			//else
              //  break;
                }
        }
		//printf("\n");
    printf("--------------------------------------------------------\n");
    exit(0);
}

void addCourseInfo(courseInfo num[],int *p)
{

    int b=1;
    int x,y,z;
    int counter[*p-1];
    char stra[40]; char *ptr=stra; // these are the strings used to store values before storing them to the struct
    char strb[10];
    char strc[10];
    int year;
    printf("Enter course name: " );
    scanf(" %40[^\n]s",stra);
    *ptr=toupper(*ptr);
    strcpy(C.courseName,stra);
    strcpy(A[*p],stra);

    C.courseID = *p+1;
    printf("A ID struct:%d\n", C.courseID);
    while(1)
    {   int c=0;
        printf("Enter faculty code (format xx) : ");
        scanf(" %s", stra);
        strcpy(strc,stra);
        printf("Enter subject code (format xx) : ");
        scanf(" %s", strb);
        strcat(stra,strb);
        strcat(strcat(strc,","),strb);
        printf("Enter level code (format xxx) : ");
        scanf(" %s", strb);
        strcat(stra,"-");
        strcat(stra,strb);
        strcat(strcat(strc,","),strb);


        for ( int k = 0 ; k < *p-1 ; k++)
        {
            counter[k] = strcmp(stra,n[k].courseCode);

            if(counter[k]==0)
            {
                c=100;
                printf("Invalid: Repeated course code (%s)!\n",stra );
            }
            else
            {
                b=0;
            }
        }
        c = c + b;
        if ( c==0)
        {
            strcat(strcat(A[*p],","),strc);
            break;
        }

    }
    strcpy(C.courseCode,stra);
    while (1)
    {
    printf("Enter number of sections: ");
    scanf("%d",&x);
    if ( x>3 || x<=0)
    {
        printf("Maximum course section is 3\n");
    }
    else break;
    }

    printf("Enter section code 1: ");
    scanf("%d", &y);
    C.courseSection[0]=y;

    if (x==1)
    {
    strcat(A[*p],",");
    sprintf(stra,"%d",y);
    strcat(A[*p],stra);
    strcat(A[*p],",0,0");

    }

    else if ( x == 2)
    {
        while(1)
        {
            printf("Enter section code 2: " );
            scanf("%d", &s );
            if ( y==s)
            {
                printf("Invalid: Repeated section code!\n");
            }
            else
            {
                C.courseSection[1]=s;
                sprintf(stra,"%d",s);
                sprintf(strb,"%d",y);
                strcat(strcat(A[*p],","),strb);
                strcat(strcat(strcat(A[*p],","),stra),",0");

                break;

            }

        }
    }
    else if ( x == 3)
    {

            while(1)
            {
                printf("Enter section code 2: " );
                scanf("%d", &s );
                if ( y==s)
                {
                    printf("Invalid: Repeated section code!\n");
                }
                else
                {
                    C.courseSection[1]=s;

                    break;
                }

            }
            while(1)
            {
                printf("Enter section code 3: " );
                scanf("%d", &z );
                if ( z==s||z==y)
                {
                    printf("Invalid: Repeated section code!\n");
                }
                else if ( z!= s && z!=y)
                {
                    C.courseSection[2]=z;
                    sprintf(stra,"%d",s);//2
                    sprintf(strb,"%d",y);//1
                    sprintf(strc,"%d",z);//3
                    strcat(strcat(A[*p],","),strb);
                    strcat(strcat(A[*p],","),stra);
                    strcat(strcat(A[*p],","),strc);
                    break;
                }
            }
    }

    char t[1];
    char t1[5];
    char *ptr_t =t;
    printf("Enter semester (S, F or W) : ");
    scanf("%s", t);
    *ptr_t=toupper(*ptr_t);
    //strcat(A[number_addcourse],ptr_t);
    strcat(strcat(A[*p],","),ptr_t);
    printf("Enter year (format yyyy) : ");
    scanf("%d", &year);
    sprintf(stra,"%d",year);
    strcat(strcat(A[*p],","),stra);
    strcat(A[*p],"\n");
    strcpy(C.Term,t);
    sprintf(t1,"%d",year);
    strcat(C.Term,t1);
    printf("Term is %s\n", C.Term);


    num[*p]=C;

    printf("Course Added\n");
    printf("****%d\n",n[*p].courseID);
    printf("****%s\n",n[*p].courseCode );
    printf("****%s\n",n[*p].courseName );

    printf("Index *****%d\n",*p );
    *p=*p+1;
    printf("Value of M : %d\n", M );

	exit(0);
}

void saveCourseInfo(const char A[][200],int *M)
{


    FILE *save = fopen("courseinfo.csv","w");
    if ( !save)
    {
        printf("Unable to open file");
    }
    for ( int i = 0 ; i < *M ; i++)
    {
        fprintf(save,"%s",A[i]);

    }
    fclose(save);

exit(0);
}

void searchCourseID(courseInfo n[],int *M)
{
    int n1;
    printf("Enter course ID :");
    scanf("%d", &n1);
    if ( n1<=0&&n1>*M)
    {


        printf("Course ID %d was not found.\n", n1 );
    }
    else
    {
    printf("\nID  Name\t\tCode\t\tTerm\tSections\n");
    printf("--------------------------------------------------------\n");
    displayScourse(n ,n1 -1);
    }
    exit(0);
}

void searchCourseName(courseInfo n[],int M)
{
    int counter=0;
    int counter_index=0;
    char str[40];
    char *ptr=str;
    printf("Enter course name: ");
    scanf(" %40[^\n]s",str);
    *ptr=toupper(*ptr);
    for ( int i =0; i <M;i++)
    {
        if(strcmp(str,n[i].courseName)==0)
        {
            counter++;
            counter_index=i;
            printf("\nID  Name\t\tCode\t\tTerm\tSections\n");
            printf("--------------------------------------------------------\n");
            displayScourse(n,counter_index);

        }
    }
    if (counter ==0)
    {
        printf("Course name \"%s\" was not found.\n",str );
    }
}

void searchCourseTerm(courseInfo n[],int *M)
{
    char str1[10];char* ptr = str1;
    char str2[10];
    int counter =0;
    int index[10];
    printf("Enter semester (S,F or W): ");
    scanf(" %s", str1);
    *ptr=toupper(*ptr);
    printf("Enter year (format yyyy) ");
    scanf(" %s",str2 );
    strcat(str1,str2);
    for (int i = 0 ; i < *M;i++)
    {
        if(strcmp(str1,n[i].Term)==0)
        {
            index[counter]=i;
            counter++;

        }
    }
    if (counter!=0)
    {
        printf("\nID  Name\t\tCode\t\tTerm\tSections\n");
        printf("--------------------------------------------------------\n");


        for(int c = 0 ; c<counter;c++)
        {
            displayScourse(n,index[c]);
        }
    }
    else
    {
        printf("Course Term \"%s\" was not found.\n",str1 );
    }


}

void displayScourse(courseInfo n[],int n1 )
{

    printf("%d %s\t\t%s\t%s\t",n[n1].courseID, n[n1].courseName,n[n1].courseCode,n[n1].Term);
    for(int i=0;i<3;i++){
    if (n[n1].courseSection[0]!=0)
    printf("%d,",n[n1].courseSection[i]);
    //puts(" ");
    else
        break;
}
exit(0);
}



void commandLine(int command) {
char x[2],*ptr=x;
    while(1){
   if(command==1)
    addCourseInfo(n,&M);
  else if(command==2)
    searchCourseID(n,&M);
  else if(command==3)
    searchCourseName(n,M);
  else if(command==4)
    searchCourseTerm(n,&M);
  else if(command==5)
    displayCourseInfo(n,M);
  else if(command==6)
    saveCourseInfo(A,&M);
  else if(command==7)
   {
	printf("Do you want to save data? (Y/N)");
	scanf("%s",x);
	if(toupper(*ptr)=='Y')
	{
		saveCourseInfo(A,&M);
		printf("Saved\n");
	}
	else
	{
    printf("Good Bye.");
    break;}}
  else
	{
        printf("Wrong selection.");
        displayMenu();
    }
}}

void displayMenu() {
  int command = 0;
  while (command != 7) {
    printf("------------\n");
    printf("Assignment 3\n");
    printf("------------\n");
    printf("1. Add a new course\n");
    printf("2. Search for a course by course ID\n");
    printf("3. Search for a course by course Name\n");
    printf("4. Search for all courses by term\n");
    printf("5. Display course data\n");
    printf("6. Save course data\n");
    printf("7. Exit\n");
    printf("Please enter a selection: ");
    scanf("%d", & command);
    commandLine(command);
  }
}

int main(){
  sampleCourseInfo();
  loadCourseInfo();
  displayMenu();
  return 0;
}
