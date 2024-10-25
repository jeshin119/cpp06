#!/bin/bash
chmod +x "a.out"

#######################char#######################
echo -e "\033[0;33m********************char test********************\033[0;m"

echo "./a.out h" && ./a.out h && echo 

echo "./a.out *" && ./a.out \* && echo

echo "./a.out ." && ./a.out . && echo
#######################char#######################

#######################int#######################
echo -e "\033[0;33m********************int test********************\033[0;m"

echo "./a.out 0" && ./a.out 0 && echo

echo "./a.out 42" && ./a.out 42 && echo

echo "./a.out +42" && ./a.out +42 && echo

echo "./a.out 2147483647" && ./a.out 2147483647 && echo

echo "./a.out 2147483648" && ./a.out 2147483648 && echo

echo "./a.out -2147483648" && ./a.out "-2147483648" && echo

echo "./a.out -2147483648888888" && ./a.out "-2147483648888888" && echo

echo "./a.out 44444444444444444444" && ./a.out "-2147483648888888" && echo
#######################int#######################

#######################float#######################
echo -e "\033[0;33m********************float test********************\033[0;m"

echo "./a.out 0.1f" && ./a.out 0.1f && echo

echo "./a.out -2.666f" && ./a.out "-2.666f" && echo

echo "./a.out 123123.0099999f" && ./a.out "123123.0099999f" && echo

echo "./a.out 12312415124.1123123123123f" && ./a.out 12312415124.1123123123123f && echo
#######################float#######################

#######################double#######################
echo -e "\033[0;33m********************double test********************\033[0;m"

echo "./a.out 1.1" && ./a.out 1.1 && echo

echo "./a.out 444444444.4444444444444" && ./a.out 444444444.4444444444444 && echo

echo "./a.out 444444444444.0" && ./a.out 444444444444.0 && echo
#######################double#######################

#######################pseudo literal#######################
echo -e "\033[0;33m********************pseudo literal test********************\033[0;m"

echo "./a.out nan" && ./a.out "nan" && echo

echo "./a.out nanf" && ./a.out "nanf" && echo

echo "./a.out +inf" && ./a.out "+inf" && echo

echo "./a.out +inff" && ./a.out "+inff" && echo

echo "./a.out -inf" && ./a.out "-inf" && echo

echo "./a.out -inff" && ./a.out "-inff" && echo
#######################pseudo literal#######################

#######################error#######################
echo "./a.out ++123" && ./a.out "++123" && echo 

echo "./a.out 0123" && ./a.out "0123" && echo 

echo "./a.out 000123" && ./a.out "000123" && echo 

echo "./a.out 111111111111111111111111111111111111111111" && ./a.out "111111111111111111111111111111111111111111" && echo

echo "./a.out hi" && ./a.out "hi" && echo 

echo "./a.out hi123" && ./a.out "hi123" && echo 

echo "./a.out 123.123." && ./a.out "123.123." && echo 

echo "./a.out .123" && ./a.out ".123" && echo 

echo "./a.out 123ff123" && ./a.out "123ff123" && echo 

echo "./a.out .123f" && ./a.out ".123f" && echo 

echo "./a.out 123f" && ./a.out "123f" && echo 

echo "./a.out 123ff" && ./a.out "123ff" && echo 

echo "./a.out --123" && ./a.out "--123" && echo 
#######################error#######################
