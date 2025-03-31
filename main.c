#include <stdio.h>
#include <string.h>
FILE *fp; //used to read the file
FILE *fw; //used to write the file
char skip_header[100]; //used to skip the header

/* Question#1 */
void name(int order, char name[]) //Name each lake
{
  switch (order){
    case 0:
      strcpy(name, "Superior");
      return;
    case 1:
      strcpy(name, "Michigan");
      return;
    case 2:
      strcpy(name, "Huron");
      return;
    case 3:
      strcpy(name, "Erie");
      return;
    case 4:
      strcpy(name, "Ontario");
      return;
    case 5:
      strcpy(name, "St. Clair");
      return;
    default:
      strcpy(name, "GLTotal");
      return;
  }
}

void question1(double avg1[], int object1, double avg2[], int object2) //Question#1 main function
{
  // sum1 and sum2 hold the cumulative sum for each lake + GLTotal.
  double sum1[] = {0,0,0,0,0,0,0}; 
  double sum2[] = {0,0,0,0,0,0,0};
  // Counters track how many daily data points belong to each year.
  int count1 = 0;
  int count2 = 0;

  /* used to skip the header */
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);

  /* define to read the file */
  double Sup, Mich, Huron, Erie, Ont, StClr, GLTotal;
  int day, year;

  /* read the file until the end */
  while (fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %lf", &year, &day, &Sup, &Mich, &Huron, &Erie, &Ont, &StClr, &GLTotal) != EOF)
    {
      /* if the year matches object1, add to sum1 */
      if (year == object1)
      {
        sum1[0] += Sup;
        sum1[1] += Mich;
        sum1[2] += Huron;
        sum1[3] += Erie;
        sum1[4] += Ont;
        sum1[5] += StClr;
        sum1[6] += GLTotal;
        count1++;
      }
      /* if the year matches object2, add to sum2 */
      if (year == object2)
      {
        sum2[0] += Sup;
        sum2[1] += Mich;
        sum2[2] += Huron;
        sum2[3] += Erie;
        sum2[4] += Ont;
        sum2[5] += StClr;
        sum2[6] += GLTotal;
        count2++;
      }
    }
      
  /* average */
  for (int i = 0; i < 7; i++)
    {
      avg1[i] = sum1[i] / count1;
      avg2[i] = sum2[i] / count2;
    }

  /* print */
  printf("Year Superior Michigan    Huron     Erie  Ontario  St.Clair GLTotal\n");
  printf("%d ", object1);
  for (int i = 0; i < 7; i++)
    {
      printf("%8.2lf ", avg1[i]);  
    }
  printf("\n%d ", object2);
  for (int i = 0; i < 7; i++)
    {
      printf("%8.2lf ", avg2[i]);  
    }
  fclose(fp);
  return;
}

/* Question#2 */
void question2(double avg1[], int object1, double avg2[], int object2)
{
  double max1 = -1, max2 = -1;
  double min1 = 2, min2 = 2;
  int maxOrder1, maxOrder2;
  int minOrder1, minOrder2;
  char lake_name[20];
  /* find max and min among 6 lakes for each year */
  for (int i = 0; i < 6; i++)
    {
      if (avg1[i] > max1) max1 = avg1[i];
      if (avg1[i] < min1) min1 = avg1[i];
      if (avg2[i] > max2) max2 = avg2[i];
      if (avg2[i] < min2) min2 = avg2[i];
    }
  /* print out which lake is max or min */
  for (int i = 0; i < 6; i++)
    {
      if (avg1[i] == max1)
      {
        name(i, lake_name);
        printf("The lake with highest ice concentration in %d is %s with %.2lf\n", object1, lake_name, max1);
      }
      if (avg1[i] == min1)
      {
        name(i, lake_name);
        printf("The lake with lowest ice concentration in %d is %s with %.2lf\n", object1, lake_name, min1);
      }
      if (avg2[i] == max2)
      {
        name(i, lake_name);
        printf("The lake with highest ice concentration in %d is %s with %.2lf\n", object2, lake_name, max2);
      }
      if (avg2[i] == min2)
      {
        name(i, lake_name);
        printf("The lake with lowest ice concentration in %d is %s with %.2lf\n", object2, lake_name, min2);
      }
    }
  return;
}
/* Question#3 */
typedef struct
{
  int year, day;
} time;

typedef struct
{
  char name[20];
  double max_consertration;
  int amount;
  time when[10];
} lake;
/* Initialize each lake structure */
void initialize (lake where[])
{
  for (int i = 0; i < 6; i++)
    {
      name (i, where[i].name);
      where[i].max_consertration = -1;
      where[i].amount = 0;
    }
}
/* Print each lake's max concentration and all days that match */
void outputQ3(lake where[])
{
  for (int i = 0; i < 6; i++)
  {
    printf("The %s lake has maximum ice concentration %lf on:\n", where[i].name, where[i].max_consertration);
    for (int j = 0; j < where[i].amount; j++)
    {
      printf("year %d, day %d\n", where[i].when[j].year, where[i].when[j].day);
    }     
  }
  return;
}

void question3(lake lakes[])
{
  fp = fopen("g2023_2024_ice.dat", "r");

  /* skip header */
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  
  double conc[6], GLTotal;
  int day, year;
  initialize (lakes);
  while (fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %lf", &year, &day, conc, conc+1, conc+2, conc+3, conc+4, conc+5, &GLTotal) != EOF)
    {
      for (int i = 0; i < 6; i++)
        {
          /* if we find a bigger concentration, update that lake's info */
          if (conc[i] > lakes[i].max_consertration)
          {
            lakes[i].max_consertration = conc[i];
            lakes[i].amount = 0;
            lakes[i].when[lakes[i].amount].year = year;
            lakes[i].when[lakes[i].amount].day = day;
            lakes[i].amount++;
          }
            /* if equal to current max, record it as well (tie) */
          else if (conc[i] == lakes[i].max_consertration)
            {
              lakes[i].when[lakes[i].amount].year = year;
              lakes[i].when[lakes[i].amount].day = day;
              lakes[i].amount++;
            }
        }       
    }

  outputQ3(lakes);
  
  fclose(fp);
  return;
}

/* Question#4 */

void question4(lake lakes[])
{
  double max_conc = -1;

  /* find the global maximum across the 6 lakes */
  for (int i = 0; i < 6; i++)
  {
    if (lakes[i].max_consertration > max_conc)
    {
      max_conc = lakes[i].max_consertration;
    }
  }
  /* print out any lake that has this global maximum */
  for (int i = 0; i < 6; i++)
    {
      if (lakes[i].max_consertration == max_conc)
      {
        for (int j = 0; j < lakes[i].amount; j++)
          {
            printf ("Year: %d  Day: %d %s Lake\n", lakes[i].when[j].year, lakes[i].when[j].day, lakes[i].name);
          }
      }
    }
  
  return;
}

/* Question#5 */
void question5()
{
  /* sikp header of CSV */
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);

  double Sup, Mich, Huron, Erie, Ont, StClr, GLTotal;
  int day, year;

  /* read each line, write day + 6 lake values to fw */
  while (fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %lf", &year, &day, &Sup, &Mich, &Huron, &Erie, &Ont, &StClr, &GLTotal) != EOF)
    {
      fprintf(fw, "%d %lf %lf %lf %lf %lf %lf\n", day, Sup, Mich, Huron, Erie, Ont, StClr);
    }

  
  fclose(fp);
  fclose(fw);
  return;
}

/* Question 8 */
/*   store daily data for 3 years for each of the 6 lakes. */
typedef struct{
  int day;
  double conc;
}dayHistory;

typedef struct{
  int size;
  dayHistory dayData[366];
}yearHistory;

typedef struct{
  yearHistory yearData[3];
}lakeHistory;

void DE(lakeHistory lake_data[], int year_order) //Data Entry
{
  int day, year;
  double lakes[6], GLTotal;
  /* sikp header of CSV */
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);
  fgets(skip_header, sizeof(skip_header), fp);

  
  /* read each line */
  while (fscanf(fp, "%d %d %lf %lf %lf %lf %lf %lf %lf", &year, &day, lakes, lakes+1, lakes+2, lakes+3, lakes+4, lakes+5, &GLTotal) != EOF)
    {
      /* put data into each lake for this specific year */
      for (int lake_order = 0; lake_order < 6; lake_order++) 
      {
          lake_data[lake_order].yearData[year_order].dayData[day].day = day;
          lake_data[lake_order].yearData[year_order].dayData[day].conc = lakes[lake_order];
      }
    }
  fclose(fp);
  return;
}
void initializeQ8(lakeHistory lake_data[]) //Sets all day/conc to -1 for each lake, year, day
{
  for (int year = 0; year < 3; year++)
    {
      for (int i = 0; i < 6; i++)
       {
          for (int j = 0; j < 366; j++)
            {
              lake_data[i].yearData[year].dayData[j].conc = -1;
              lake_data[i].yearData[year].dayData[j].day = -1;
            }
          lake_data[i].yearData[year].size = 0;
        }
    }
}
/* Finds 'origin' and 'destination' for daily data
   by checking where we hit conc == -1 in each yearData.
   It tries to define the valid day range for output.*/
void comp(yearHistory yearData[], int *origin, int *destination) 
{
  *destination = 0;
  *origin = 366;
  for (int j = 0; j < 3; j++)
    {
      for (int i = 1; i < 366; i++)
        {
          if (yearData[j].dayData[i].conc == -1 && i >= *destination)
          {
            *destination = i;
            break;
          }
        }
      for (int i = 365; i > 0; i--)
        {
          if (yearData[j].dayData[i].conc == -1 && i <=  *origin)
          {
            *origin = i;
            break;
          }
        }
      
    }
}

/*Uses comp() to find the range to print.
   Then loops through days (origin+1 .. destination-1),
   printing day plus 3 columns (one for each of the 3 years).
   If data is missing, prints "NaN".*/
void resultOutput (lakeHistory lakeData[], int lakeOrder)
{
  int origin, destination;
  comp(lakeData[lakeOrder].yearData, &origin, &destination);
  origin++;
  destination--;
  for (int actDay = origin; (actDay <= destination || actDay >= origin); actDay++)
    {
      if (actDay == 366) actDay = 1;
      fprintf(fw, "%d ", actDay);
        for (int i = 0; i < 3; i++)
          {
            if (lakeData[lakeOrder].yearData[i].dayData[actDay].conc != -1)
            {
              fprintf(fw, "%lf ", lakeData[lakeOrder].yearData[i].dayData[actDay].conc);
            }
            else
            {
              fprintf(fw, "NaN ");
            }
          }
      fprintf(fw, "\n");
    }
      
  return;
}

  

void question8()
{
  lakeHistory lakedata[6];
  initializeQ8(lakedata);
  
  fp = fopen("g2021_2022_ice.dat", "r");
  DE(lakedata, 0);
  fp = fopen("g2022_2023_ice.dat", "r");
  DE(lakedata, 1);
  fp = fopen("g2023_2024_ice.dat", "r");
  DE(lakedata, 2);

  fw = fopen("Lake Superior data.txt", "w");
  resultOutput(lakedata, 0);
  fclose(fw);
  fw = fopen("Lake Michigan data.txt", "w");
  resultOutput(lakedata, 1);
  fclose(fw);
  fw = fopen("Lake Huron data.txt", "w");
  resultOutput(lakedata, 2);
  fclose(fw);
  fw = fopen("Lake Erie data.txt", "w");
  resultOutput(lakedata, 3);
  fclose(fw);
  fw = fopen("Lake Ontario data.txt", "w");
  resultOutput(lakedata, 4);
  fclose(fw);
  fw = fopen("Lake St. Clair data.txt", "w");
  resultOutput(lakedata, 5);
  fclose(fw);
  
  
  return;
}

int main(void) {
  double avg1[7], avg2[7];
  int year1, year2;
  /********** Question#1 **********/
  printf("Question#1\n");
  fp = fopen("g2023_2024_ice.dat", "r");
  question1 (avg1, 2023, avg2, 2024);
  printf("\n\n");
  /********** Question#2 **********/
  printf("Question#2\n");
  question2 (avg1, 2023, avg2, 2024);
  printf("\n\n");
  /********** Question#3 **********/
  printf("Question#3\n");
  lake lakes[6];
  question3(lakes);
  printf("\n\n");
  /********** Question#4 **********/
  printf("Question#4\n");
  question4(lakes);
  printf("\n\n");
  /********** Question#5 & #6 **********/
  fp = fopen("g2023_2024_ice.dat", "r");
  fw = fopen("Question5&6.txt", "w");
  question5();
  printf("\n\n");
  /********** Question#7 **********/
  printf("Question#7\n");
  fp = fopen("g2021_2022_ice.dat", "r");
  question1 (avg1, 2021, avg2, 2022);
  printf("\n");
  fp = fopen("g2022_2023_ice.dat", "r");
  question1 (avg1, 2022, avg2, 2023);
  printf("\n");
  fp = fopen("g2023_2024_ice.dat", "r");
  question1 (avg1, 2023, avg2, 2024);
  printf("\n\n");
  /********** Question#8 **********/
  question8();
  
  
  return 0;
}


