#include <iostream>
using namespace std;
const int ARRAY_SIZE = 10;

void displayArray(const int arr[]);  // Declare the function prototype here

void enterNumbers(int arr[]) {
    int num;

    cout << "Enter numbers for the array (enter -1 to stop):" << endl;
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << "Enter number " << i + 1 << ": ";
        cin >> num;
        if (num == -1) {
            break; 
        }
        arr[i] = num;
    }
    cout << "Array after inserting values: " << endl;
    displayArray(arr);  // Call displayArray() without embedding it in cout
}

void fillArray(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = (i + 1) * 10;
    }
}

bool isArrayFull(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] == 0) {
            return false; 
        }
    }
    return true; 
}

bool isEmpty(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (!arr[i] == 0) {
            return false; 
        }
    }
    return true; 
}

void displayArray(const int arr[]) {
    cout << "Array contents: ";
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insert(int arr[], int num) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] == 0) { 
            arr[i] = num;  
            cout<< "inserted..."<< endl;
            return;        
        }
    }
    cout << "Array is full, cannot insert " << num << "." << endl;
}

void del(int arr[], int pos) {
    if (pos < 0 || pos >= ARRAY_SIZE) {
        cout << "Invalid position!" << endl;
        return;
    }

    for (int i = pos; i < ARRAY_SIZE - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    arr[ARRAY_SIZE - 1] = 0;
}
int findLoc(int arr[], int num){
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] > num) {     
            return (i);
        }
    }
    return -1;
}

void BubbleSort(int arr[]) {
    for (int i = 0; i < ARRAY_SIZE - 1; ++i) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; ++j) {
            if (arr[j] > arr[j + 1] && arr[j] != 0 && arr[j + 1] != 0) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
int LinearSearch(int arr[], int key) {
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        if (arr[i] == key) {
            return i+1; 
        }
    }
    return -1; 
}
int BinarySearch(int arr[], int key) {
    BubbleSort(arr);
    int low = 0;
    int high = ARRAY_SIZE - 1;
    while (low <= high) {
        int mid = (low + high) / 2; // Find the middle element

        if (arr[mid] == key) {
            return mid + 1; // Return the position (1-based index)
        } else if (arr[mid] < key) {
            low = mid + 1; // Search in the right half
        } else {
            high = mid - 1; // Search in the left half
        }
    }

    return -1; // Key not found
}


void choseSearchTyoe(int arr[], int key){
    int numberChoase;
    cout<< "chose your favorate search:"<< endl;
    cout<< "[1] Linner search"<< endl;
    cout<< "[2] Binary search"<< endl;
    cout<< "enter the number:"<< endl;
    cin >> numberChoase;
    if (numberChoase == 1) {  // Use == for comparison, not =
            int index = LinearSearch(arr, key);
            if (index == -1) {
                cout << "Key (" << key << ") not found using Linear Search." << endl;
            } else {
                cout << "The index for (" << key << ") is = " << index << endl;
            }
        } else if (numberChoase == 2) {
            int index = BinarySearch(arr, key);
            if (index == -1) {
                cout << "Key (" << key << ") not found using Binary Search." << endl;
            } else {
                cout << "The index for (" << key << ") is = " << index << endl;
            }
        } else {
            cout << "Invalid number, please choose 1 or 2." << endl;
    }
}

int main() {
    int myArray[ARRAY_SIZE] = {0}; 
    int num,choice;
    
    // Menu loop to allow user to perform various actions
    while (true) {
        cout << "\n========= MENU =========\n";
        cout << "1. Enter numbers into the array\n";
        cout << "2. Fill array with random values\n";
        cout << "3. Display array\n";
        cout << "4. Insert a number\n";
        cout << "5. Delete a number at a position\n";
        cout << "6. Sort array (Bubble Sort)\n";
        cout << "7. Search for a number (choose Linear/Binary)\n";
        cout << "8. Check if array is full\n";
        cout << "9. Check if array is empty\n";
        cout << "0. Exit\n";
        cout << "==========================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                enterNumbers(myArray);  // Allows user to manually input numbers
                break;
            case 2:
                fillArray(myArray);  // Fills array with default values
                cout << "Array has been filled with default values.\n";
                break;
            case 3:
                displayArray(myArray);  // Displays the current state of the array
                break;
            case 4:
                cout << "Enter the number to insert: ";
                cin >> num;
                insert(myArray, num);  // Inserts a number
                break;
            case 5:
                cout << "Enter the position to delete (0 to " << ARRAY_SIZE - 1 << "): ";
                cin >> num;
                del(myArray, num);  // Deletes a number at the specified position
                cout << "Number deleted.\n";
                break;
            case 6:
                BubbleSort(myArray);  // Sorts the array using Bubble Sort
                cout << "Array has been sorted.\n";
                break;
            case 7:
                cout << "Enter the number to search: ";
                cin >> num;
                choseSearchTyoe(myArray, num);  // Asks user to choose Linear or Binary search
                break;
            case 8:
                isArrayFull(myArray) ? cout << "The array is full.\n" : cout << "The array is not full.\n";
                break;
            case 9:
                isEmpty(myArray) ? cout << "The array is empty.\n" : cout << "The array is not empty.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                return 0;  // Exits the program
            default:
                cout << "Invalid choice, please try again.\n";
                break;
        }
    }
    return 0;
}
