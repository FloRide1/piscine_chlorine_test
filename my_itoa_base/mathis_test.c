#include <criterion/criterion.h>



char *my_itoa_base(int n, char *s, const char *base);


Test (Basics, 42_hexa)
{
    char *s = malloc(100);
    cr_assert_str_eq(my_itoa_base(42, s, "0123456789ABCDEF"), "2A");
    free(s);
}

Test (Basics, neg_32_hexa)
{
    char *s = malloc(100);
    cr_assert_str_eq(my_itoa_base(-32, s, "0123456789abcdef"), "-20");
    free(s);
}


Test (Basics, 12_01)
{
    char *s = malloc(100);
    cr_assert_str_eq(my_itoa_base(12, s, "01"), "1100");
    free(s);
}


Test (Basics, 80_6)
{
    char *s = malloc(100);
    cr_assert_str_eq(my_itoa_base(80, s, "0123456"), "143");
    free(s);
}
