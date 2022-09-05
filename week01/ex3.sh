mkdir folder_1
echo `date`
sleep 3
touch folder_1/root.txt
echo `date`
sleep 3
ls -tr / > folder_1/root.txt


echo `date`
sleep 3
mkdir folder_2

echo `date`
sleep 3
touch folder_2/home.txt
ls -tr ~  > folder_2/home.txt

cat folder_1/root.txt
cat folder_2/home.txt
