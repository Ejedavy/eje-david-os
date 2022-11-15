> ex2.txt
> ../week01/file.txt
echo David > ../week01/file.txt
link ../week01/file.txt _ex2.txt >> ex2.txt
echo "i-node is: $(ls -i ../week01/file.txt | awk '{print $1}')" >> ex2.txt
find ../ -inum $(ls -i ../week01/file.txt | awk '{print $1}') >> ex2.txt
find ../ -inum $(ls -i ../week01/file.txt | awk '{print $1}') -exec rm {} \; >> ex2.txt