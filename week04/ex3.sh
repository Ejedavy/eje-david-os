gcc -o ex3 ex3.c 
./ex3 3 &
for n in {1 2 3};
do	
		echo $n
		pstree
		sleep 5
done