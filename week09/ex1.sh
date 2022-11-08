gcc ex1.c -o ex1
echo "10 page frames:" > ex1.txt
./ex1 10 >> ex1.txt
echo -e "\n50 page frames:" >> ex1.txt
./ex1 50 >> ex1.txt
echo -e "\n100 page frames:" >> ex1.txt
./ex1 100 >> ex1.txt