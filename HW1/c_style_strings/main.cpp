#include <iostream>
/*
Write the following functions, but do not use any standard library functions. Create a test for each one using interesting words and sentences from your favorite history or science book.

· char* strdup(const char*), that copies a C-style string into memory it allocates on the free store.

· char* findx(const char* s, const char* x), that finds the first occurrence of the C-style string x in s.
*/
// Count number of chars in char* 
int count_char(const char* input){
    int counter = 0;

    while(input[counter] != '\0'){
        counter++;
    }
    return counter;
}
// Copies a C-style string into memory it allocates on the free store.
char* strdup(const char* input){
    auto count = count_char(input);
    char* output = new char[count];
    for(int x =0; x < count; x++){
        output[x] = input[x];
    }
    return output;
}

// finds the first occurrence of the C-style string x in s.
char* findx(const char* s, const char* x){

    auto s_count = count_char(s);
    auto x_count = count_char(x);

    for(int count_across_s = 0; count_across_s < (s_count); ++count_across_s){
        if(s[count_across_s] == x[0]){
                    char* possibly_found = (char*) s+count_across_s;

            for (int count_across_x = 0; count_across_x < s_count; ++count_across_x){
                if (s[count_across_x + count_across_s] != x[count_across_x]) {
                    break;
                }
                if (count_across_x == x_count -1) {
                    return possibly_found;
                }
            }
        }
    }
    char* a = (char*) "not found";
    return a;
    
}
int main(){
    const char* test = "If you prick us do we not bleed? If you tickle us do we not laugh? If you poison us do we not die? And if you wrong us shall we not revenge?";
    auto out = strdup(test);
    std::cout << "--Test string--: " << test << std::endl;
    std::cout << "--Char* on stack--: " << out << std::endl;
    std::cout << findx(test, "asdf") << std::endl;
}