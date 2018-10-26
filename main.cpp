#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::stoi;
using std::stold;

// Print the values stored in the day array
void printDay(string dayArray[]){
    cout << "Day number-----------: " << dayArray[0] << endl;
    cout << "Sum------------------: " << dayArray[1] << endl;
    cout << "Max------------------: " << dayArray[2] << endl;
    cout << "Min------------------: " << dayArray[3] << endl;
    cout << "Count----------------: " << dayArray[4] << endl;
}

// Print the values stored in the week array
void printWeek(string weekArray[]){
    cout << "Week number----------: " << weekArray[0] << endl;
    cout << "Sum------------------: " << weekArray[1] << endl;
    cout << "Max------------------: " << weekArray[2] << endl;
    cout << "Min------------------: " << weekArray[3] << endl;
    cout << "Largest delta on day-: " << weekArray[4] << endl;
    cout << "Count----------------: " << weekArray[5] << endl;
}

// This function resets the day array, itterates the day numumber, and if it is moving to the 8th day it resets the
// week array
void moveToNextDay(string dayArray[], string weekArray[]){

    // Gets the count of the current day and the last day ans turns them into int's
    int curCount = stoi(dayArray[4]);
    int prevCount = stoi(dayArray[5]);

    // Sets the largest delta to the current day if the current count is greater than the prev count
    int temp = curCount - prevCount;
    if(temp > 0){
        weekArray[4] = dayArray[0];
    }

    // Adds one to the current day
    string curDay = dayArray[0];
    int curDayInt = stoi(curDay);
    curDayInt++;
    curDay = to_string(curDayInt);

    // Resets the day array
    dayArray[1] = "0.0";
    dayArray[2] = "0.0";
    dayArray[3] = "0.0";
    dayArray[5] = dayArray[4];
    dayArray[4] = "0";

    // Resets the week array if the day = 8
    if(curDay == "8"){
        weekArray[0] = "2";
        weekArray[1] = "0.0";
        weekArray[2] = "0.0";
        weekArray[3] = "0.0";
        weekArray[4] = "0.0";
        weekArray[5] = "0";
        weekArray[6] = "0.0";
    }
    dayArray[0] = curDay;

}

// This function checks if the value is a a max for the day and the week
void checkMax(string dayArray[], string weekArray[], string entry){
    // Lines 75 - 242 ensure the strings ate the same length
    long entryBefore = 0;
    long entryAfter = 0;
    bool decimalE = false;

    // Get entry size before and after decimal
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

    // Check if the entry had a decimal and if not add one
    if(! decimalE){
        string temp = entry;
        temp += ".0";
        entryAfter = 1;
        entry = temp;
    }

    // Get day sum size before and after decimal
    long dayArrayBefore = 0;
    long dayArrayAfter = 0;
    for(unsigned long i = 0; i < dayArray[2].length(); i++){
        char currentCharEntry = dayArray[2].at(i);

        if(currentCharEntry == '.'){
            long curr = dayArray[2].length() - dayArrayBefore;
            for(unsigned long j = 1; j < curr; j++){
                dayArrayAfter++;
            }
            break;
        }
        dayArrayBefore++;
    }

    // Get week sum size before and after decimal
    long weekArrayBefore = 0;
    long weekArrayAfter = 0;
    for(unsigned long i = 0; i < weekArray[2].length(); i++){
        char currentCharEntry = weekArray[2].at(i);
        if(currentCharEntry == '.'){
            long curr = weekArray[2].length() - weekArrayBefore;
            for(unsigned long j = 1; j < curr; j++){
                weekArrayAfter++;
            }
            break;
        }
        weekArrayBefore++;
    }

    // If the number starts with a decimal add a 0 to the front
    if(entryBefore == 0){
        string temp = entry;
        temp.insert(0, 1, '0');
        entry = temp;
        entryBefore++;
    }

    // The next 8 if statements add 0's the the front and rear of the strings to make sure they are the same size
    if(entryBefore < dayArrayBefore){
        string temp = entry;
        for(long i = entryBefore; i < dayArrayBefore; i++){
            temp.insert(0, 1, '0');
            entryBefore++;
        }
        entry = temp;
    }

    if(entryBefore > dayArrayBefore){
        string temp = dayArray[2];
        for(long i = dayArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            dayArrayBefore++;
        }
        dayArray[2] = temp;
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
        string temp = dayArray[2];
        for(long i = dayArrayAfter; i < entryAfter; i++){
            temp += '0';
            dayArrayAfter++;
        }
        dayArray[2] = temp;
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
        string temp = weekArray[2];
        for(long i = weekArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            weekArrayBefore++;
        }
        weekArray[2] = temp;
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
        string temp = weekArray[2];
        for(long i = weekArrayAfter; i < entryAfter; i++){
            temp += '0';
            weekArrayAfter++;
        }
        weekArray[2] = temp;
    }

    // Checks if the entry is greater than the day max
    for(long i = 0; i < entry.length(); i++) {
        char currentCharEntry = entry.at(i);
        char currentCharDay = dayArray[2].at(i);

        int currentIntEntry = (int)currentCharEntry;
        int currentIntDay = (int)currentCharDay;

            if (currentIntEntry > currentIntDay) {
                dayArray[2] = entry;
                break;
            }
    }

    // Checks if the entry is greater than the week max
    for(long i = 0; i < entry.length(); i++) {
        char currentCharEntry = entry.at(i);
        char currentCharWeek = weekArray[2].at(i);

        int currentIntEntry = (int)currentCharEntry;
        int currentIntWeek = (int)currentCharWeek;

        if(currentIntEntry > currentIntWeek) {
            weekArray[2] = entry;
            break;
        }
    }
}

// This function checks if the value is a a min for the day and the week
void checkMin(string dayArray[], string weekArray[], string entry){
    // Everything doen to line 386 is commented in check min function

    long entryBefore = 0;
    long entryAfter = 0;
    bool decimalE = false;

    if(dayArray[4] == "1"){
        dayArray[3] = entry;
        weekArray[3] = entry;
    }

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
    for(unsigned long i = 0; i < dayArray[3].length(); i++){
        char currentCharEntry = dayArray[3].at(i);

        if(currentCharEntry == '.'){
            long curr = dayArray[3].length() - dayArrayBefore;
            for(unsigned long j = 1; j < curr; j++){
                dayArrayAfter++;
            }
            break;
        }
        dayArrayBefore++;
    }


    long weekArrayBefore = 0;
    long weekArrayAfter = 0;
    for(unsigned long i = 0; i < weekArray[3].length(); i++){
        char currentCharEntry = weekArray[3].at(i);
        if(currentCharEntry == '.'){
            long curr = weekArray[3].length() - weekArrayBefore;
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
        string temp = dayArray[3];
        for(long i = dayArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            dayArrayBefore++;
        }
        dayArray[3] = temp;
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
        string temp = dayArray[3];
        for(long i = dayArrayAfter; i < entryAfter; i++){
            temp += '0';
            dayArrayAfter++;
        }
        dayArray[3] = temp;
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
        string temp = weekArray[3];
        for(long i = weekArrayBefore; i < entryBefore; i++){
            temp.insert(0, 1, '0');
            weekArrayBefore++;
        }
        weekArray[3] = temp;
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
        string temp = weekArray[3];
        for(long i = weekArrayAfter; i < entryAfter; i++){
            temp += '0';
            weekArrayAfter++;
        }
        weekArray[3] = temp;
    }

    // Checks if the entry is less than the day min
    for(long i = 0; i < entry.length(); i++) {
        char currentCharEntry = entry.at(i);
        char currentCharDay = dayArray[3].at(i);

        int currentIntEntry = (int)currentCharEntry;
        int currentIntDay = (int)currentCharDay;

        if (currentIntEntry < currentIntDay) {
            dayArray[3] = entry;
            break;
        }
    }

    // Checks if the entry is less than the week min
    for(long i = 0; i < entry.length(); i++) {
        char currentCharEntry = entry.at(i);
        char currentCharWeek = weekArray[3].at(i);

        int currentIntEntry = (int)currentCharEntry;
        int currentIntWeek = (int)currentCharWeek;

        if(currentIntEntry < currentIntWeek) {
            weekArray[3] = entry;
            break;
        }
    }
}

// This function does string addition.
void addEntry(string dayArray[], string weekArray[], string entry){
    int carryD = 0;
    int carryW = 0;

    string countDayChar = dayArray[4];
    int countDayInt = stoi(countDayChar);
    countDayInt++;
    countDayChar = to_string(countDayInt);
    dayArray[4] = countDayChar;

    string countWeekChar = weekArray[5];
    int countWeekInt = stoi(countWeekChar);
    countWeekInt++;
    countWeekChar = to_string(countWeekInt);
    weekArray[5] = countWeekChar;

    for(long i = 1; i <= entry.length(); i++){
        // Gets the current char in entry and day sum
        char currentCharEntry = entry[entry.size() - i];
        char currentCharDayArray = dayArray[1][dayArray[1].size() - i];

        // Add if not a decimal
        if(currentCharEntry != '.') {
            // Turn current char's to int's
            int entryChar = (int) currentCharEntry - 48;
            int dayArrayChar = (int) currentCharDayArray - 48;

            // Add int's and check if it carry's
            int charSum = entryChar + dayArrayChar + carryD;
            if (charSum > 9) {
                carryD = 1;
                charSum = charSum - 10;
            }
            else{
                carryD = 0;
            }

            // Turn int back into char
            currentCharDayArray = '0' + charSum;
            dayArray[1][dayArray[1].size() - i] = currentCharDayArray;
            // Insert char into string and save into day array
            if (carryD == 1 && i == entry.length()) {
                dayArray[1].insert(0, 1, '0');
                currentCharDayArray = '0' + carryD;
                dayArray[1][dayArray[1].size() - i - 1] = currentCharDayArray;
            }
        }

        // Does the same thing as the code above but for the week array
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

// This function endures that the strings are the same length
string prepareToAdd(string dayArray[], string weekArray[], string entry){
    // everything in this function is commented in checkMax function
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

    return entry;
}

// This function makes sure the input is a positive real number
string inputEntry(string dayArray[], string weekArray[]){
    // Gets a input from the user ans stores it as a string
    string entry;
    cout << "Input >> ";
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
        moveToNextDay(dayArray, weekArray);
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

// The main function
int main() {
    // Initialize arrays
    string dayArray[6] = {"1", "0.0", "0.0", "0.0", "0", "0"};
    string weekArray[7] = {"1", "0.0", "0.0", "0.0", "0.0", "0", "0.0"};

    string entry;
    // Always run
    while(true) {
        entry = inputEntry(dayArray, weekArray);
        // Terminate if exit signal is entered
        if(entry == "-1"){
            return 0;
        }
        // Exit when 14 days have padded
        if(entry == "-2"){
            cout << "Day storage full, Goodbye.";
            return 0;
        }
        // Run the real meaty part is the input is valid
        if(entry != "0") {
            entry = prepareToAdd(dayArray, weekArray, entry);
            addEntry(dayArray, weekArray, entry);
            checkMax(dayArray, weekArray, entry);
            checkMin(dayArray, weekArray, entry);
        }
    }
}