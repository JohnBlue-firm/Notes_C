/*

以下示範 memset / memcpy / strncpy

destination可嘗試用更短的string_length
雖然可能不會有錯誤, 或是可能使用到program本身的空間
但是已經佔用到未知空間, 容易有undefine behavior, 不建議這樣做

*/

#include <stdio.h>
#include <string.h>

int main() {
    char original_string[] = "Hello, world!";
    int string_length = strlen(original_string) + 1;  // Include null terminator



    // **memset example: Initialize an array with a specific value**
    char destination_array1[string_length];
    memset(destination_array1, '\0', string_length);     // Fill with \0
    memset(destination_array1, '*', string_length - 1);  // Fill with asterisks

    printf("memset: '%s'\n", destination_array1);  // Output: ********* (null terminator)



    // **memcpy example: Copy a string (be cautious with buffer overflows)**
    char destination_array2[string_length];
    memcpy(destination_array2, original_string, string_length);

    printf("memcpy: '%s'\n", destination_array2);  // Output: Hello, world!

    // int ori_num[3] = {...}; int des_num[3]; >> memecpy(des_num, ori_num, sizeof(ori_num));




    // **strcpy example (safer alternative: strncpy)**
    char destination_array3[string_length];  // Ensure enough space for the entire string + null terminator

    // Use strncpy to avoid potential buffer overflows if the source string is unexpectedly long
    strncpy(destination_array3, original_string, string_length - 1);  // Copy up to (length - 1) characters
    destination_array3[string_length - 1] = '\0';  // Manually add null terminator for safety

    printf("strncpy (safer): '%s'\n", destination_array3);  // Output: Hello, world!

    return 0;
}
