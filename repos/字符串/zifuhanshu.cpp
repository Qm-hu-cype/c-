#include<stdio.h>
#include<conio.h>
#include<assert.h>
#include<stdlib.h>
#define _CRT_SECURE_NO_WARNINGS 1

//char* my_strstr(const char* p1, const char* p2) {
//	assert(p1 != NULL);
//	assert(p1 != NULL);
//	const char* s1 = p1;
//	const char* s2 = p2;
//	const char* cur = p1;
//	if (*p2 == '\0')
//		return (char*)p1;
//	while (*cur) {
//		s1 = cur;
//		s2 = p2;
//		while ((*s1 != '\0') && (*s2 != '\0') && (*s1 == *s2)) {
//			s1++;
//			s2++;
//
//		}
//		if (*s2 == '\0')
//			return (char*)cur;
//		cur++;
//	}
//	return NULL;
//}
//int main() {
//	const char* p1 = "abcdef";
//	const char* p2 = "def";
//	char* ret = my_strstr(p1, p2);
//	if (ret == NULL)
//		printf("×Ó´®²»´æÔÚ\n");
//	else
//		printf("%s\n",ret);
//	system("pause");
//