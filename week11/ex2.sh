sudo mkdir -p lofsdisk/bin
sudo mkdir -p lofsdisk/usr
sudo mkdir -p lofsdisk/usr/lib/x86_64-linux-gnu
sudo mkdir -p lofsdisk/usr/lib64

sudo cp /bin/{bash,echo,ls,cat} lofsdisk/bin/
sudo cp /lib64/ld-linux-x86-64.so.2 lofsdisk/usr/lib64/
sudo cp /lib/x86_64-linux-gnu/{libtinfo.so.6,libdl.so.2,libc.so.6} lofsdisk/usr/lib/x86_64-linux-gnu/

sudo ln -s usr/lib lofsdisk/lib
sudo ln -s usr/lib64 lofsdisk/lib64

gcc ex2.c -o ex2.out

sudo bash -c "echo 'David' > lofsdisk/file1"
sudo bash -c "echo 'Eje' > lofsdisk/file2"

./ex2.out > ex2.txt

echo >> ex2.txt

sudo cp ex2.out lofsdisk/ex2.out
sudo chroot lofsdisk ./ex2.out >> ex2.txt
