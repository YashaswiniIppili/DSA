#include <stdio.h>
#include <stdlib.h>

int maxlength(char *p)
{
	int count = 0, max, length = 0;
	char ch;
	int i = 0;
	while(p[i]!='\0')
	{
		ch = p[i];
		if(ch == '('||ch == '['|| ch == '{')
		{
			count++;
			length++;
		}
		else
		{
			count--;
			length++;
			if(count==0)
				max = length;
		}
		i++;
	}
	return max;
}

int main()
{
	char s[100];
	printf("Enter a string of paranthesis : ");
	scanf("%s",s);
	int x;
	x=maxlength(s);
	printf("%d",x);
}