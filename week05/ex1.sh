# !/bin/bash


gcc  -o publisher publisher.c
gcc  -o subscriber subscriber.c

for ((i = 0; i < $1; ++i)) do
    gnome-terminal -- "./subscriber"
done

gnome-terminal -- "./publisher" $1

rm publisher
rm subscriber