// Q.1A Program to get the starting and ending indices of a substring
// Author: Pranjal Timsina, 20BDS0392
// Date: 23rd February, 2021

#include <bits/stdc++.h>

bool match(std::string string_a, std::string string_b) {
    /*
    Function to return whether string_a matches with string_b

    Parameters:
        std::string string_a --> The first string to compare
        std::string string_b --> The second string to compare

    Returns:
        bool:
            true, if string_a and string_b are the same
            false, if string_a and string_b are different
    */

    // If the strings are of different length, returns false immediately
    if (string_a.length() != string_b.length()){
        return false;
    }

    // Iterates both of the strings and returns false once it encounters a mismatch
    for (int i = 0; i < string_a.length(); i++) {
        if (string_a[i] != string_b[i]) {
            return false;
        }
    }

    // This code is only reached when the above loop runs fully without mismatch
    return true;
}

std::string get_substr(std::string main_string, int start_index, int sub_string_length) {
    /*
    Function to return a substring of main_string starting at start_index with length sub_string_length

    Parameters:
        std::string main_string --> The main string from where the substring will be extracted from
        int start_index --> The starting index of the substring
        int sub_string_length --> The length of the substring to be extracted

    Returns:
        string:
            Empty string if parameters are invalid
            The required substring if the parameters are valid
    */

    // Handling cases where the parameters are invalid
    if (start_index < 0 || start_index >= main_string.length()){
        return "";
    } else if (start_index+sub_string_length >= main_string.length()){
        return "";
    }

    std::string new_string{main_string[start_index]}; // Initializing string

    // Concatenating the new_string with characters upto main_string[start_index+sub_string_length]
    for (int i = start_index+1; i < start_index+ sub_string_length; i++) {
        new_string += main_string[i];
    }

    return new_string;

}

void search(std::string &main_string, std::string &sub_string, int &main_string_length, int &sub_string_length) {

    for (int i=0; i < main_string_length; i++) {

        if (main_string[i] == sub_string[0] && match(get_substr(main_string, i, sub_string_length), sub_string))
            std::cout << i << " to " << i + sub_string_length-1 << std::endl;

    }

}

int main() {

    std::string main_string;
    cout << "Enter the main string: " << endl;
    std::getline(std::cin, main_string);

    std::string sub_string;
    cout << "Enter the sub string: " << endl;
    std::getline(std::cin, sub_string);

    int main_string_length = main_string.length();
    int sub_string_length = sub_string.length();

    if (sub_string_length > main_string_length) {

        std::cout << "Sub string is lager than main string" << std::endl;
        return 0;

    } else if (sub_string == main_string) {

        std::cout << "0 to " << main_string_length-1 << std::endl;
        return 0;

    }

    search(main_string, sub_string, main_string_length, sub_string_length);

    return 0;

}
