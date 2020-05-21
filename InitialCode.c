#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

int Validate_Pwd(char[]);

/* Validate the Pwd */
int Validate_Pwd(char a[])
{
    char c;
    int len,flag1=0,flag2=0,flag3=0,flag4=0;
	
    len=stringlength(a);
	
    if(len<6)
    flag1=1;
    else
    {
        for(int i=0;i<len;i++)
        if((a[i]>=48&&a[i]<=58))
        {
            flag2=0;

            break;
        }
        else
        flag2=1;

        for(int i=0;i<len;i++)
        if((a[i]>=65&&a[i]<=90))
        {
            flag3=0;

            break;
        }
        else
        flag3=1;

        for(int i=0;i<len;i++)
        if(a[i]=='#'||a[i]=='$'||a[i]=='*'||a[i]=='&')
        {
            flag4=0;

            break;
        }
        else
        flag4=1;


    }
    if(flag1==1||flag2==1||flag3==1||flag4==1)
    return 0;
    else
    return 1;
}

int stringlength(char s[])
{
 int i;
  for (i = 0; s[i] != '\0'; ++i);
  return i;
}

/* Cunit testcases to validate the Pwd */
void ValidatePwd_CUnitTest()
{
 /*("Enter your password that should satisfy the following criteria\n1.
password should contain atleast one capital letter\n2. 
should have one digit from(o-9)\n3. atleast one special charecter($,*,#,&)\n4.
length should be atleast 6\n");*/

CU_ASSERT(Validate_Pwd("J1$abc") == 1);
CU_ASSERT(Validate_Pwd("J1$abcwyie") == 1);
CU_ASSERT(Validate_Pwd("J1abef") == 0);
CU_ASSERT(Validate_Pwd("b1dac") == 0);
	
}

int main()
 {
CU_initialize_registry();
CU_pSuite suite = CU_add_suite("Validate_Password_test", 0, 0);

CU_add_test(suite, "ValidatePwd",ValidatePwd_CUnitTest);
	
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();

return 0;
}
