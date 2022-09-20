#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *print_any_base(unsigned long num, unsigned int base) {
    int i, d, count = 0;
    unsigned long n = num;
    char ch;
    if (n == 0) {
        count = 1;
    } else {
        while (n > 0) {
            ++count;
            n /= base;
        }
    }
    char *result = (char *) malloc(sizeof(char) * (count + 1));
    n = num;
    if (n == 0) {
        result[0] = '0';
    } else {
        for (i = 0; i < count; ++i) {
            d = n % base;
            n /= base;
            if (d < 10) {
                result[count - i - 1] = '0' + d;
            } else {
                result[count - i - 1] = ('A' + d - 10);
            }
        }
    }
    result[count] = '\0';
    return result;
}

unsigned int count_vowel(char *str) 
{ 
    int vowels = 0; 
  
    while ((*str)) { 
    	if(*str == 'a' | *str == 'e' | *str == 'i' | *str == 'o' | *str == 'u' | *str == 'A' | *str == 'E' | *str == 'I' | *str == 'O' | *str == 'U'){ 
    		vowels++;
    	}
    	str++;
    } 
  
    return vowels; 
}

char *reverse_words(char *str)
{
    int n = strlen(str);

    char *rev_str = (char *)malloc(sizeof(char) * n);
    strcpy(rev_str, str);
    
    int start = 0;
    int end = 0;

    while (end < n)
    {
        if (rev_str[end] == ' ')
        {
            int si = start;
            int ei = end - 1;
            while (si < ei)
            {
                char temp = rev_str[si];
                rev_str[si] = rev_str[ei];
                rev_str[ei] = temp;
                si++;
                ei--;
            }
            start = end + 1;
        }
        end = end + 1;
    }

    int si = start;
    int ei = end - 1;
    while (si < ei)
    {
        char temp = rev_str[si];
        rev_str[si] = rev_str[ei];
        rev_str[ei] = temp;
        si++;
        ei--;
    }

    si = 0;
    ei = n - 1;
    while (si < ei)
    {
        char temp = rev_str[si];
        rev_str[si] = rev_str[ei];
        rev_str[ei] = temp;
        si++;
        ei--;
    }

    return rev_str;
}

void rotate_in_place(char *str, unsigned int disp){
	int i ;
	char ch;
	if(disp < 0 || disp > 2600){
		printf("ERROR: disp must be 0 <= disp <= 2600");
	}
	else{
		disp = disp%26; 
		for(i = 0; str[i] != '\0'; ++i){
			ch = str[i]; 
			if(ch >= 'a' && ch <= 'z'){ 
				ch = ch + disp;
				if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1; 
				}
			str[i] = ch;
			}
			else if(ch >= 'A' && ch <= 'Z'){
				ch = ch + disp; 
				if(ch > 'Z'){
					ch = ch - 'Z' + 'A' - 1; 
				} 
				str[i] = ch;
			}			
		}			
		printf("Rotated String: %s\n", str);
	}
}

int countBits(unsigned char cbits)
{
    int num_bits = 0;
    while (cbits > 0)
    {
        num_bits += cbits & 1;
        cbits >>= 1;
    }
    return num_bits;
}
void paritize(void *p, unsigned int num_bytes)
{
    int i = 0, num_bits;
    unsigned char copy;
    
    unsigned char cbits = (1 << 7) & 0xff;

    for (i = 0; i < num_bytes; i++)
    {

        copy = cbits & *(char *)(p + i);

        num_bits = countBits(copy);

        if (num_bits % 2 == 1)
        {
            *(char *)(p + i) |= (1 << 7);
        }
        else
        {
            *(char *)(p + i) &= ~(1 << 7);
        }
    }
}



unsigned long swap_bytes(unsigned long n){
	unsigned long val = 0, mask = 0xFF;
	val |= ((n & mask) << 8)|((n & (mask << 8))>>8);
	val |= ((n & (mask << 16)) << 8)|((n & (mask << 24))>>8);
	val |= ((n & (mask << 32)) << 8)|((n & (mask << 40))>>8);
	val |= ((n & (mask << 48)) << 8)|((n & (mask << 56))>>8);
	return val;
}







int main() {
	int vowel = 0;
    unsigned long num;
    unsigned int base;
    printf("Enter a positive integer: ");
    scanf("%lu", &num);
    printf("Enter base: ");
    scanf("%u", &base);
    printf("%s\n", print_any_base(num, base));
    
  	char vstr[100];
  	
  	printf("Input a string: ");
	fgets(vstr, 100, stdin);
	scanf("%[^\n]%*c", vstr);
    vowel=count_vowel(vstr);
    printf("Vowels in above string: %d\n",vowel); 
 	
 	char str[1000];
 	
    printf("Enter input string : ");
    fgets(str, 1000, stdin);
	scanf("%[^\n]%*c", str);
    char *rev = reverse_words(str);
    printf("Output : %s\n", rev);
    
    char torotateString[100], ch;
	int i, displacement;
 
	printf("Enter the string to rotate: ");
	fgets(torotateString, 1000, stdin);
	scanf("%[^\n]%*c", torotateString);
	printf("Enter displacement: ");
	scanf("%d", &displacement);
	rotate_in_place(torotateString, displacement);
    
	
	unsigned long q6test = 0x12345678deadbeef;
	printf("0x%lx\n", swap_bytes(q6test));
		
	unsigned int a = 0xdeadbeef;
	
	paritize(&a, sizeof(a));
	printf("%x\n", a);
	


	
 	
 	
 	
    
    
  	
    
    return 0;
}

