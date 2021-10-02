#include <criterion/criterion.h>
#include "connect4.h"

Test(Basics, simple_test)
{
    char *mat[11] = {
        "----------",
        "----------",
        "----------",
        "---X------",
        "---XXO----",
        "----OOO---",
        "----------",
        "----------",
        "-XXXX-----",
        "----------",
        "----------"
    };
    cr_assert_eq(connect4(mat, 10, 10), RETURN_PLAYER_1);
}

Test(Basics, horinzontal_test)
{
    char *mat[11] = {
        "-----",
        "-----",
        "--X--",
        "---X-",
        "---XX",
        "--XOO",
        "---O-",
        "---O-",
        "OXXXX",
        "OOO--",
        "-----"
    };
    int got = connect4(mat, 5, 10);
    cr_assert_eq(got, RETURN_PLAYER_1, "Horizontal: E:%d - G:%d\n", RETURN_PLAYER_2, got);
}

Test(Basics, vertical_test)
{
    char *mat[11] = {
        "-----",
        "-----",
        "--X--",
        "---X-",
        "---XX",
        "--XOO",
        "---O-",
        "---O-",
        "OXXOX",
        "OOO--",
        "-----"
    };
    int got = connect4(mat, 5, 10);
    cr_assert_eq(got, RETURN_PLAYER_2, "Vertical: E:%d - G:%d\n", RETURN_PLAYER_2, got);
}

Test(Basics, diagonal_test)
{
    char *mat[11] = {
        "-----",
        "-X---",
        "--X--",
        "---X-",
        "---XX",
        "--XOO",
        "---O-",
        "---O-",
        "OXX-X",
        "OOO--",
        "-----"
    };
    cr_assert_eq(connect4(mat, 5, 10), RETURN_PLAYER_1);
}

Test(Basics, diagonal_two_test)
{
    char *mat[11] = {
        "-----",
        "-X---",
        "--X-O",
        "---O-",
        "--OXX",
        "-OXOO",
        "---O-",
        "---O-",
        "OXX-X",
        "OOO--",
        "-----"
    };
    cr_assert_eq(connect4(mat, 5, 10), RETURN_PLAYER_2);
}

Test(Basics, both_win_test)
{
    char *mat[11] = {
        "-----",
        "-X---",
        "--X--",
        "---X-",
        "---XX",
        "--XOO",
        "---O-",
        "---O-",
        "OXXOX",
        "OOO--",
        "-----"
    };
    cr_assert_eq(connect4(mat, 5, 10), ERROR_RETURN);
}

Test(Basics, no_win_test)
{
    char *mat[11] = {
        "-----",
        "-X---",
        "--X--",
        "---X-",
        "---X-",
        "--X-O",
        "---O-",
        "---O-",
        "OXXOX",
        "OOO--",
        "-----"
    };
    cr_assert_eq(connect4(mat, 5, 10), DEFAULT_RETURN);
}

Test(Errors, null)
{
    cr_assert_eq(connect4(NULL, 10, 10), ERROR_RETURN);
}

Test(Errors, zero_size)
{
    char *mat[1] = {
      ""
    };
    cr_assert_eq(connect4(mat, 1, 0), ERROR_RETURN);
}
