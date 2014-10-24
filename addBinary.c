#include <stdio.h>
#include <string.h>

void addBinary(char *s, char *s1, char *s2)
{
    int i;
    int l, l1, l2;
    int tmp;
    char x[10000];

    l1 = strlen(s1);
    l2 = strlen(s2);
    l = 0;
    tmp = 0;
    memset(x, 0x00, sizeof(x));
    while(l1 > 0 && l2 > 0)
    {
        tmp = s1[--l1] + s2[--l2] + tmp - 2 * '0'; 
        switch(tmp)
        {
            case 0:
                tmp = 0;
                x[l++] = '0';
                break;
            case 1:
                tmp = 0;
                x[l++] = '1';
                break;
            case 2:
                tmp = 1;
                x[l++] = '0';
                break;
            case 3:
                tmp = 1;
                x[l++] = '1';
                break;
            default:
                printf("xxx err\n");
                break;
        }
    }
    while(l1 > 0)
    {
        tmp = s1[--l1] + tmp - '0';
        if(tmp == 0)
        {
            tmp = 0;
            x[l++] = '0';
        }
        else if (tmp == 1)
        {
            tmp = 0;
            x[l++] = '1';
        }
        else /* tmp == 2 */
        {
            tmp = 1;
            x[l++] = '0';
        }
   
    }
    while(l2 > 0)
    {
        tmp = s2[--l2] + tmp - '0';
        if(tmp == 0)
        {
            tmp = 0;
            x[l++] = '0';
        }
        else if (tmp == 1)
        {
            tmp = 0;
            x[l++] = '1';
        }
        else /* tmp == 2 */
        {
            tmp = 1;
            x[l++] = '0';
        }
    }
    if(tmp)
        x[l++] = '1';
    for(i = 0; i < l; i++)
    {
        s[l-i-1] = x[i];
        //s[i] = x[i];
    }
}


void add_bignumber(char *s, char *s1, char *s2)
{
	char x[1000000];
	int l1, l2, l;
	int i, tmp, carry;
	
	l1 = strlen(s1);
	l2 = strlen(s2);
	carry = 0;
	l = 0;
	
	while(l1 > 0 && l2 > 0)
	{
		tmp = s1[--l1] + s2[--l2] - 2 * '0' + carry;
		if(tmp < 10)
		{
			carry = 0;
			x[l++] = tmp + '0';
		}
		else
		{
			carry = 1;
			x[l++] = tmp % 10 + '0';
		}
	}
	while(l1 > 0)
	{
		tmp = s1[--l1] - '0' + carry;
		if(tmp < 10)
		{
			x[l++] = tmp + '0';
			carry = 0;	
		}
		else
		{
			x[l++] = tmp % 10 + '0';
			carry = 1;	
		}
	}
	while(l2 > 0)
	{
		tmp = s2[--l2] - '0' + carry;
		if(tmp < 10)
		{
			x[l++] = tmp + '0';
			carry = 0;	
		}
		else
		{
			x[l++] = tmp % 10 + '0';
			carry = 1;	
		}		
	}
	if(carry)
	{
		x[l++] = '1';
	}
	
    for(i = 0; i < l; i++)
    {
        s[l-i-1] = x[i];
        //s[i] = x[i];
    }
    s[l] = '\0';
}


int main(void)
{
    char s1[] = "100001100011111";
    char s2[] = "11111110001101100";
    char s3[1000];

    addBinary(s3, s1, s2);

    printf("s1: %s\n", s1);
    printf("s2: %s\n", s2);
    printf("s3: %s\n", s3);

    return 0;
}

