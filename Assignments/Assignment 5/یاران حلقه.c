#include <stdio.h>

int main()
{
    unsigned input, i, moves = 1;
    int nobat = 1;

    scanf("%u", &input);
    unsigned nums[input];

    for ( i = 1; i <= input; i++ )
    {
        nums[i - 1] = i;
    }

    while ( moves < input )
    {
        for ( i = 0; i < input; i++ )
        {
            if ( nums[i] != 0 )
            {
                nobat = !nobat;
                if ( nobat )
                {
                    nums[i] = 0;
                    moves++;
                }
            }
        }
    }

    for ( i = 0; i < input; i++ )
    {
        if ( nums[i] != 0 ) {
            printf("%u", nums[i]);
        }
    }
}
