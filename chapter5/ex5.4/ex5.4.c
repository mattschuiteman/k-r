 // strend pointer version

 #include <stdio.h>

 void MS_strcat(char *s, char *t);

 #include <stdio.h>

 int MS_strend(char *s, char *t);

 int main(void)
 {
     printf("Test 1: %d (expected 1)\n",
     MS_strend("hello", "lo"));

     printf("Test 2: %d (expected 0)\n",
     MS_strend("hello", "ll"));

     printf("Test 3: %d (expected 1)\n",
     MS_strend("hello", "hello"));

     printf("Test 4: %d (expected 0)\n",
     MS_strend("hello", "hello!"));

     printf("Test 5: %d (expected 1)\n",
     MS_strend("", ""));

     printf("Test 6: %d (expected 1)\n",
     MS_strend("hello", ""));

     printf("Test 7: %d (expected 0)\n",
     MS_strend("", "a"));

     printf("Test 8: %d (expected 1)\n",
     MS_strend("abcabc", "abc"));

     printf("Test 9: %d (expected 0)\n",
     MS_strend("abcdef", "defg"));

     printf("Test 10: %d (expected 1)\n",
     MS_strend("a", "a"));

     printf("Test 11: %d (expected 0)\n",
     MS_strend("a", "b"));

     printf("Test 12: %d (expected 1)\n",
     MS_strend("abcdef", "f"));

     printf("Test 13: %d (expected 0)\n",
     MS_strend("abcdef", "e"));

     printf("Test 14: %d (expected 1)\n",
     MS_strend("aaaaa", "aaa"));

     return 0;
 }

 void MS_strcat(char *s, char *t)
 {
     while (*s != '\0')
     s++;

     while ((*s++ = *t++))
     ;
 }

 int MS_strend(char *s, char *t)
 {
     char *t_begin;
     t_begin = t;
     while (*s != '\0')
     s++;

     while (*t != '\0')
     t++;

     for (; *s == *t; s--, t--)
     {
	 if (t == t_begin)
	 return 1;
     }

    return 0;
 }
