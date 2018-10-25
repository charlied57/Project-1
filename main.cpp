#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;

void printDay(string dayArray[]){
    cout << "Day number:    " << dayArray[0] << endl;
    cout << "Sum:           " << dayArray[1] << endl;
    cout << "Max:           " << dayArray[2] << endl;
    cout << "Min:           " << dayArray[3] << endl;
    cout << "Count:         " << dayArray[4] << endl;
}
void printWeek(string weekArray[]){
    cout << "Week number:   " << weekArray[0] << endl;
    cout << "Sum:           " << weekArray[1] << endl;
    cout << "Max:           " << weekArray[2] << endl;
    cout << "Min:           " << weekArray[3] << endl;
    cout << "Largest delta: " << weekArray[4] << endl;
    cout << "Count:         " << weekArray[5] << endl;
}
void moveToNextDay(string dayArray[], string weekArray[]){

    string curDay = dayArray[0];
    int curDayInt = stoi(curDay);
    curDayInt++;
    curDay = to_string(curDayInt);

    for(int i = 1; i < 4; i++){
//        cout << dayArray[i] << endl;
        dayArray[i] = "0.0";
    }
    if(curDay == "8"){
        weekArray[0] = "2";
        weekArray[1] = "0.0";
        weekArray[2] = "0.0";
        weekArray[3] = "0.0";
        weekArray[4] = "0.0";
        weekArray[5] = "0.0";
        weekArray[6] = "0.0";
        weekArray[7] = "0.0";
    }
    dayArray[0] = curDay;

}

//void checkDelta(string weekArray[], string entry){
//
//}
//
//void checkMax(string dayArray[], string weekArray[], string entry){
//
//}
//
//void checkMin(string dayArray[], string weekArray[], string entry){
//
//}

void addEntry(string dayArray[], string weekArray[], string entry){
    int carryD = 0;
    int carryW = 0;

    string countDayChar = dayArray[4];
    int countDayInt = stoi(countDayChar);
    countDayInt++;
    countDayChar = to_string(countDayInt);
    dayArray[4] = countDayChar;
//    cout << dayArray[4] << endl;

    string countWeekChar = weekArray[5];
    int countWeekInt = stoi(countWeekChar);
    countWeekInt++;
    countWeekChar = to_string(countWeekInt);
    weekArray[5] = countWeekChar;
    cout << weekArray[5] << endl;

    for(long i = 1; i <= entry.length(); i++){
        char currentCharEntry = entry[entry.size() - i];
        char currentCharDayArray = dayArray[1][dayArray[1].size() - i];

        if(currentCharEntry != '.') {
            int entryChar = (int) currentCharEntry - 48;
            int dayArrayChar = (int) currentCharDayArray - 48;

            int charSum = entryChar + dayArrayChar + carryD;
            if (charSum > 9) {
                carryD = 1;
                charSum = charSum - 10;
            }
            else{
                carryD = 0;
            }

            currentCharDayArray = '0' + charSum;
            dayArray[1][dayArray[1].size() - i] = currentCharDayArray;
            if (carryD == 1 && i == entry.length()) {
                dayArray[1].insert(0, 1, '0');
                currentCharDayArray = '0' + carryD;
                dayArray[1][dayArray[1].size() - i - 1] = currentCharDayArray;
            }
        }

        char currentCharWeekArray = weekArray[1][weekArray[1].size() - i];
        if(currentCharEntry != '.') {
            int entryChar = (int) currentCharEntry - 48;
            int weekArrayChar = (int) currentCharWeekArray - 48;

            int charSum = entryChar + weekArrayChar + carryW;
            if (charSum > 9) {
                carryW = 1;
                charSum = charSum - 10;
            }
            else{
                carryW = 0;
            }

            currentCharWeekArray = '0' + charSum;
            weekArray[1][weekArray[1].size() - i] = currentCharWeekArray;
            if (carryW == 1 && i == entry.length()) {
                weekArray[1].insert(0, 1, '0');
                currentCharWeekArray = '0' + carryW;
                weekArray[1][weekArray[1].size() - i - 1] = currentCharWeekArray;
            }
        }
    }
}

string prepareToAdd(string dayArray[], string weekArray[], string entry){
    long entryBefore = 0;
    long entryAfter = 0;
    bool decimalE = false;
    int x = 1;
    for(unsigned long i = 0; i < entry.length(); i++){
        char currentCharEntry = entry.at(i);

        if(currentCharEntry == '.'){
            long curr = entry.length() - entryBefore;
            decimalE = true;
            for(unsigned long i = 1; i < curr; i++){
                entryAfter++;
            }
        break;
        }
        entryBefore++;
    }

    if(! decimalE){
        string temp = entry;
        temp += ".0";
        entryAfter = 1;
        entry = temp;
    }

    long dayArrayBefore = 0;
    long dayArrayAfter = 0;
    for(unsigned long i = 0; i < dayArray[1].length(); i++){
        char currentCharEntry = dayArray[1].at(i);

        if(currentCharEntry == '.'){
            long curr = dayArray[1].length() - dayArrayBefore;
            for(unsigned long j = 1; j < curr; j++){
                dayArrayAfter++;
            }
            break;
        }
        dayArrayBefore++;
    }

    if(weekArray[0] == "2"){
        int x = 2;
    }


    long weekArrayBefore = 0;
    long weekArrayAfter = 0;
    for(unsigned long i = 0; i < weekArray[x].length(); i++){
        char currentCharEntry = weekArray[x].at(i);
        if(currentCharEntry == '.'){
            long curr = weekArray[x].length() - weekArrayBefore;
            for(unsigned long j = 1; j < curr; j++){
                weekArrayAfter++;
            }
            break;
        }
        weekArrayBefore++;
    }

    if(entryBefore == 0){
        string temp = entry;
        temp.insert(0, 1, '0');
        entry = temp;
        entryBefore++;
    }

    if(entryBefore < dayArrayBefore){
        string temp = entry;
        for(long i = entryBefore; i < dayArrayBefore; i++){
            temp.insert(0, 1, '0');
            entryBefore++;
        }
        entry = temp;
    }

    if(entryBefore > dayArrayBefore){
        string temp = dayArray[1];
        for(long i = dayArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            dayArrayBefore++;
        }
        dayArray[1] = temp;
    }

    if(entryAfter < dayArrayAfter){
        string temp = entry;
        for(long i = entryAfter; i < dayArrayAfter; i++){
            temp += '0';
            entryAfter++;
        }
        entry = temp;
    }

    if(entryAfter > dayArrayAfter){
        string temp = dayArray[1];
        for(long i = dayArrayAfter; i < entryAfter; i++){
            temp += '0';
            dayArrayAfter++;
        }
        dayArray[1] = temp;
    }
///////////////////////////////////////////////////////

    if(entryBefore < weekArrayBefore){
        string temp = entry;
        for(long i = entryBefore; i < weekArrayBefore; i++){
            temp.insert(0, 1, '0');
            entryBefore++;
        }
        entry = temp;
    }

    if(entryBefore > weekArrayBefore){
        string temp = weekArray[x];
        for(long i = weekArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            weekArrayBefore++;
        }
        weekArray[x] = temp;
    }

    if(entryAfter < weekArrayAfter){
        string temp = entry;
        for(long i = entryAfter; i < weekArrayAfter; i++){
            temp += '0';
            entryAfter++;
        }
        entry = temp;
    }

    if(entryAfter > weekArrayAfter){
        string temp = weekArray[x];
        for(long i = weekArrayAfter; i < entryAfter; i++){
            temp += '0';
            weekArrayAfter++;
        }
        weekArray[x] = temp;
    }

    return entry;
}

string inputEntry(string dayArray[], string weekArray[]){
    // Gets a input from the user ans stores it as a string
    string entry;
    cout << "Input a value of only digits, may contain a decimal" << endl << ">> ";
    getline(cin, entry);

    // Base cases
    // if the string is -1 then the program terminates
    if (entry == "-1") {
        return entry;
    }

    // call print day function
    if (entry == "d" || entry == "D" || entry ==  "Day") {
        printDay(dayArray);
        entry = "0";
        return entry;
    }

    //call print week function
    if (entry == "w" || entry == "W" || entry ==  "Week") {
        printWeek(weekArray);
        entry = "0";
        return entry;
    }

    // call next day function
    if (entry == "n" || entry == "N" || entry == "Next") {
        cout << dayArray[0] << endl;
        moveToNextDay(dayArray, weekArray);
        cout << dayArray[0] << endl;
        if(dayArray[0] == "15"){
            return "-2";
        }
        entry = "0";
        return entry;
    }

    // makes sure that there is only one decimal
    short decimalCounter = 0;

    // Loop to check that it is a number(no characters) with one or zero decimals
    for(unsigned long i = 0; i < entry.length(); i++){

        // gets the current character
        char currentChar = entry.at(i);

        // returns zero if the number is negative
        if (currentChar == '-'){
            entry = '0';
            return entry;
        }

        // checks if there is more than one decimal and is a digit
        if(isdigit(currentChar) || currentChar == '.'){

            // adds one to the decimal counter
            if(currentChar == '.'){
                decimalCounter++;
            }

            // if there is more than one decimal return zero
            if(decimalCounter > 1){
                cout << "Invalid entry";
                entry = '0';
                return entry;
            }
        }

        // if there is a charater that is not a digit return zero
        else{
            cout << "Invalid entry" << endl;
            entry = '0';
            return entry;
        }
    }

    // check if the number is = 0
    for(unsigned long i = 0; i < entry.length(); i++){
        char currentChar = entry.at(i);

        // if a char is not zero or . then the number is not zero
        // The program will only reach this part if the number consists of digits and one decimal
        if(currentChar != '0' && currentChar != '.'){
            return entry;
        }
    }

    // if the number is zero return zero
    entry = '0';
    return entry;
}

int main() {
    string dayArray[5] = {"1", "0.0", "0.0", "0.0", "0"};
    string weekArray[7] = {"1", "0.0", "0.0", "0.0", "0.0", "0", "0.0"};

    string entry;
    while(true) {
        entry = inputEntry(dayArray, weekArray);
        if(entry == "-1"){
            return 0;
        }
        if(entry == "-2"){
            cout << "Day storage full, Goodbye.";
            return 0;
        }
        if(entry != "0") {
            entry = prepareToAdd(dayArray, weekArray, entry);
            addEntry(dayArray, weekArray, entry);
//            checkMax(dayArray, weekArray, entry);
//            checkMin(dayArray, weekArray, entry);
//            checkDelta(weekArray, entry);
        }
    }
}