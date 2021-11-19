#include<stdio.h>
#include<conio.h>
#include<windows.h>
#pragma warning(disable : 4996)

struct Date {
    int dateDay;
    int dateMonth;
    int dateYear;
};

struct Date date;
struct Remainder {
    int remainderDay;                         
    int reaminderMonth;                            
    char note[50];
};


struct Remainder remainder;

void GetXandYCord(int xCord, int yCord)
{
    COORD xy = { 0, 0 };
    xy.X = xCord; xy.Y = yCord  ; 

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), xy);
}

void SetColor(int Forgroundcoler)
{
        int bluemagentaColer=0x0F;
        int blackColer=0xF0;

    WORD wordColer;
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO wordAttrib;
    if (GetConsoleScreenBufferInfo(outputHandle, &wordAttrib))
    {
        
        wordColer = (wordAttrib.wAttributes & blackColer) + (Forgroundcoler & bluemagentaColer);
        SetConsoleTextAttribute( outputHandle, wordColer);
    }
    return;
}




void ClearConsoleToColors(int forgroundColer, int backgroundColer)
{

    int bluemagentaColer=0x0F;
    int shiftBy=4;
    WORD wordColer = ((backgroundColer & redColer) << shiftBy) + (forgroundColer & redColer);
    HANDLE outputHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord = { 0, 0 };
  
    DWORD count;
    
    CONSOLE_SCREEN_BUFFER_INFO wordAttrib;
    SetConsoleTextAttribute(outputHandle, wordColer);
    if (GetConsoleScreenBufferInfo(outputHandle, & wordAttrib))
    {
        int Space=32
        FillConsoleOutputCharacter(outputHandle, (TCHAR).Space, wordAttrib.dwSize.X * wordAttrib.dwSize.Y, coord, &count);
        FillConsoleOutputAttribute(outputHandle, wordAttrib.wAttributes, wordAttrib.dwSize.X * wordAttrib.dwSize.Y, coord, &count);
        SetConsoleCursorPosition(outputHandle, coord);
    }
    return;
}
 

void SetColorAndBackground(int forgroundColer, int backgroundColer)
{
    int bluemagentaColer=0x0F;
    int shiftBy=4;
    WORD wordColer = ((backgroundColer & redColer) << shiftBy) + (forgroundColer & redColer);;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wordColer);
    return;
}
 














int CheckLeapYear(int year) { 


    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0))
        return 1;
    return 0;
}




boolean ValidMonth(int month){
    int firstMonth=1 ,lastMonth=12
    if ((month >= firstMonth && month <= lastMonth)) 
        return true;
}


void IncreaseMonth(int* month, int* year) { 
     
    if (*month > 12) {
        increas* year;
        *month = *month - 12;
    }
    else 
    *month=*month+1;
}








void DecreaseMonth(int* month, int* year) { 
    int smallestYearToEnter=1600;
    * month=*month-1;
    if (*month < 1) {
        * year=*year-1;
        if (*year < smallestYearToEnter) {
            printf("No record available");
            return;
        }
        *month = *month + 12;
    }
}














int GetNumberOfDays(int month, int year) { 
    switch (month) {                         
    case 1: return(31);
    case 2: if (CheckLeapYear(year) == 1)
        return(29);
          else
        return(28);
    case 3: return(31);
    case 4: return(30);
    case 5: return(31);
    case 6: return(30);
    case 7: return(31);
    case 8: return(31);
    case 9: return(30);
    case 10: return(31);
    case 11: return(30);
    case 12: return(31);
    default: return(-1);
    }
}






 const char* GetName(int day) { 
    switch (day) {
    case 1:return("Sunday");
    case 2:return("Monday");
    case 3:return("Tuesday");
    case 4:return("Wednesday");
    case 5:return("Thursday");
    case 6:return("Friday");
    case 7:return("Saturday");
    default:return("Error in getName() module.Invalid argument passed");
    }
}





int DayNumber(int day, int mon, int year) { 
    int result = 0, temp1, temp2, tempYear = year;
     int smallestYearToEnter=1600;
    year = year - smallestYearToEnter;
    while (year >= 100) {
        result = result + 5;
        year = year - 100;
    }
    int CalculateDayNumber(int day, int mon, int year,int result){
        int temp1, temp2, tempYear = year;
        result = (result % 7);
        temp1 = ((year - 1) / 4);
        temp2 = (year - 1) - temp1;
        temp1 = (temp1 * 2) + temp2;
        temp1 = (temp1 % 7);
        result = result + temp1;
        result = result % 7;
        temp2 = 0;
        for (temp1 = 1; temp1 < mon; temp1++) {
            temp2 += getNumberOfDays(temp1, tempYear);
        }
        temp2 = temp2 + day;
        temp2 = temp2 % 7;
        result = result + temp2;
        result = result % 7;
        if (tempYear > 2000)
            result = result + 1;
        result = result % 7;
        return result
    }

    return CalculateDayNumber(int day, int mon, int year,int result);
}








const char* GetDay(int day, int month, int year) {
    int day;
    int smallestYearToEnter=1600;

    if (!(ValidMonth(month))) {
        return("Invalid month value");
    }
    if (!(day >= 1 && day <= getNumberOfDays(month, year))) {
        return("Invalid date");
    }
    if (year >= smallestYearToEnter) {
        day = DayNumber(day, month, yy);
        day = day % 7;
        return(getName(day));
    }
    else {
        return("Please give year more than 1600");
    }
}








int CheckNote(int day, int month) {
    FILE* fp;
    fp = fopen("note.dat", "rb");
    if (fp == NULL) {
        printf("Error in Opening the file");
    }
    // R: specifies the pointer to the block of memory
    while (fread(&R, sizeof(R), 1, fp) == 1) {
        if (R.day == day && R.month == month) {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}























void PrintMonth(int month, int year, int x, int year) { 
int smallestYearToEnter=1600;
    int nod, day, cnt, d = 1, x1 = x, y1 = y, isNote = 0;
    if (!ValidMonth(month)) {
        printf("INVALID MONTH");
        _getch();
        return;
    }
    if (!(year >= smallestYearToEnter)) {
        printf("INVALID YEAR");
        _getch();
        return;
    }
    GetXandYCord(20, y);
    // Print date 
    printf("---------------------------\n");
    GetXandYCord(25, 6);
    switch (month) {
    case 1: printf("January"); break;
    case 2: printf("February"); break;
    case 3: printf("March"); break;
    case 4: printf("April"); break;
    case 5: printf("May"); break;
    case 6: printf("June"); break;
    case 7: printf("July"); break;
    case 8: printf("August"); break;
    case 9: printf("September"); break;
    case 10: printf("October"); break;
    case 11: printf("November"); break;
    case 12: printf("December"); break;
    }
    printf(" , %d", year);
    GetXandYCord(20, 7);
    printf("---------------------------");
    year += 3;
    GetXandYCord(x, y);
    printf("S   M   T   W   T   F   S   ");
    y++;
    nod = GetNumberOfDays(month, year);
    day = DayNumber(d, month, year);
    switch (day) { //locates the starting day in calender
    case 0:
        x = x;
        cnt = 1;
        break;
    case 1:
        x = x + 4;
        cnt = 2;
        break;
    case 2:
        x = x + 8;
        cnt = 3;
        break;
    case 3:
        x = x + 12;
        cnt = 4;
        break;
    case 4:
        x = x + 16;
        cnt = 5;
        break;
    case 5:
        x = x + 20;
        cnt = 6;
        break;
    case 6:
        x = x + 24;
        cnt = 7;
        break;
    default:
        printf("INVALID DATA FROM THE getOddNumber()MODULE");
        return;
    }
    GetXandYCord(x, y);
    if (cnt == 1) {
        SetColor(12);
    }
    if (checkNote(d, month) == 1) {
        SetColorAndBackground(15, 12);
    }
    printf("%02d", d);
    SetColorAndBackground(15, 1);
    for (d = 2; d <= nod; d++) {
        if (cnt % 7 == 0) {
            y++;
            cnt = 0;
            x = x1 - 4;
        }
        x = x + 4;
        cnt++;
        GetXandYCord(x, y);
        if (cnt == 1) {
            SetColor(12);
        }
        else {
            SetColor(15);
        }
        if (checkNote(d, month) == 1) {
            SetColorAndBackground(15, 12);
        }
        printf("%02d", d);
        SetColorAndBackground(15, 1);
    }
    GetXandYCord(8, year + 2);
    SetColor(14);
    printf("Press 'n'  to Next, Press 'p' to Previous and 'q' to Quit");
    GetXandYCord(8, year + 3);
    printf("Red Background indicates the NOTE, Press 's' to see note: ");
    SetColor(15);
}























void AddNote() {
    FILE* fp;
    fp = fopen("note.dat", "ab+");
    system("cls");
    GetXandYCord(5, 7);
    printf("Enter the date(Day Month): ");
    scanf_s("%d %d", &R.day, &R.month);
    GetXandYCord(5, 8);
    printf("Enter the Note(50 character max): ");
    fflush(stdin);
    scanf(" %[^\n]", R.note);
    if (fwrite(&R, sizeof(R), 1, fp)) {
        GetXandYCord(5, 12);
        puts("Note is saved sucessfully");
        fclose(fp);
    }
    else {
        GetXandYCord(5, 12);
        SetColor(12);
        puts("\aFail to save!!\a");
        //Clear color
        SetColor(15);
    }
    GetXandYCord(5, 15);
    printf("Press any key............");
    _getch();
    fclose(fp);
}


void showNote(int month) {
    FILE* fp;
    int i = 0, isFound = 0;
    system("cls");
    fp = fopen("note.dat", "rb");
    if (fp == NULL) {
        printf("Error in opening the file");
    }
    while (fread(&R, sizeof(R), 1, fp) == 1) {
        if (R.mm == mm) {
            GetXandYCord(10, 5 + i);
            printf("Note %d Day = %d: %s", i + 1, R.day, R.note);
            isFound = 1;
            i++;
        }
    }
    if (isFound == 0) {
        GetXandYCord(10, 5);
        printf("This Month contains no note");
    }
    GetXandYCord(10, 7 + i);
    printf("Press any key to back.......");
    _getch();
}

void MakeChoice(int numberOfOperation){
    switch (numberOfOperation) {
        case 1:
            printf("Enter date (DD MM YYYY) : ");
            scanf_s("%d %d %d", &date.dd, &date.mm, &date.yy);
            printf("Day is : %s", getDay(date.dd, date.mm, date.yy));
            printf("\nPress any key to continue......");
            _getch();
            break;
        case 2:
            printf("Enter month and year (MM YYYY) : ");
            scanf_s("%d %d", &date.mm, &date.yy);
            system("cls");
            while (ch != 'q') {
                printMonth(date.mm, date.yy, 20, 5);
                ch = _getch();
                if (ch == 'n') {
                    increase_month(&date.mm, &date.yy);
                    system("cls");
                    printMonth(date.mm, date.yy, 20, 5);
                }
                else if (ch == 'p') {
                    decrease_month(&date.mm, &date.yy);
                    system("cls");
                    printMonth(date.mm, date.yy, 20, 5);
                }
                else if (ch == 's') {
                    showNote(date.mm);
                    system("cls");
                }
            }
            break;
        case 3:
            AddNote();
            break;
        case 4:
            exit(0);
        }
}
















int main() {
    ClearConsoleToColors(15, 1);
    SetConsoleTitleA("Calender Project - Programming-technique.blogspot.com");
    int choice;
    char ch = 'a';
    while (1) {
        system("cls");
        printf("1. Find Out the Day\n");
        printf("2. Print all the day of month\n");
        printf("3. Add Note\n");
        printf("4. EXIT\n");
        printf("ENTER YOUR CHOICE : ");
        scanf_s("%d", &choice);
        system("cls");
        
        MakeChoice(choice)

    }
    return 0;
}
