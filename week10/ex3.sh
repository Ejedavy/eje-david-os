> _ex3.txt
echo David > _ex3.txt
chmod a-x _ex3.txt
ls -lah | grep _ex3.txt > ex3.txt
chmod uo+rwx _ex3.txt
ls -lah | grep _ex3.txt >> ex3.txt
chmod g+rwx _ex3.txt
ls -lah | grep _ex3.txt >> ex3.txt
echo "1) rw- rw- --- (The user and group has read and write)
2) rwx rwx r-x (The user and group has all the permissions, read and execute for other)
3) rwx rwx rwx (All categories have All permissions)" >> ex3.txt