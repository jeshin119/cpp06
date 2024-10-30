#!/bin/bash
chmod +x "./convert"

#######################char#######################
echo -e "\033[0;33m********************char test********************\033[0;m"

echo "./convert h" && ./convert h && echo 

echo "./convert *" && ./convert \* && echo

echo "./convert ." && ./convert . && echo
#######################char#######################

#######################int#######################
echo -e "\033[0;33m********************int test********************\033[0;m"

echo "./convert 0" && ./convert 0 && echo

echo "./convert 42" && ./convert 42 && echo

echo "./convert +42" && ./convert +42 && echo

echo "./convert 2147483647" && ./convert 2147483647 && echo

echo "./convert 2147483648" && ./convert 2147483648 && echo

echo "./convert -2147483648" && ./convert "-2147483648" && echo

echo "./convert -2147483648888888" && ./convert "-2147483648888888" && echo

echo "./convert 44444444444444444444" && ./convert "44444444444444444444" && echo
#######################int#######################

#######################float#######################
echo -e "\033[0;33m********************float test********************\033[0;m"

echo "./convert 0.1f" && ./convert 0.1f && echo

echo "./convert -2.666f" && ./convert "-2.666f" && echo

echo "./convert 123123.0099999f" && ./convert "123123.0099999f" && echo

echo "./convert 12312415124.1123123123123f" && ./convert 12312415124.1123123123123f && echo
#######################float#######################

#######################double#######################
echo -e "\033[0;33m********************double test********************\033[0;m"

echo "./convert 1.1" && ./convert 1.1 && echo

echo "./convert 444444444.4444444444444" && ./convert 444444444.4444444444444 && echo

echo "./convert 444444444444.0" && ./convert 444444444444.0 && echo
#######################double#######################

#######################pseudo literal#######################
echo -e "\033[0;33m********************pseudo literal test********************\033[0;m"

echo "./convert nan" && ./convert "nan" && echo

echo "./convert nanf" && ./convert "nanf" && echo

echo "./convert +inf" && ./convert "+inf" && echo

echo "./convert +inff" && ./convert "+inff" && echo

echo "./convert -inf" && ./convert "-inf" && echo

echo "./convert -inff" && ./convert "-inff" && echo
#######################pseudo literal#######################

#######################error#######################
echo "./convert ++123" && ./convert "++123" && echo 

echo "./convert 0123" && ./convert "0123" && echo 

echo "./convert 000123" && ./convert "000123" && echo 

echo "./convert 111111111111111111111111111111111111111111" && ./convert "111111111111111111111111111111111111111111" && echo

echo "./convert hi" && ./convert "hi" && echo 

echo "./convert hi123" && ./convert "hi123" && echo 

echo "./convert 123.123." && ./convert "123.123." && echo 

echo "./convert .123" && ./convert ".123" && echo 

echo "./convert 123ff123" && ./convert "123ff123" && echo 

echo "./convert .123f" && ./convert ".123f" && echo 

echo "./convert 123f" && ./convert "123f" && echo 

echo "./convert 123ff" && ./convert "123ff" && echo 

echo "./convert --123" && ./convert "--123" && echo 
#######################error#######################
