printf "\033[2J"
printf "\033(0"

printf "\033[10;5H┌────────┐"
printf "\033[18;5H└────────┘"

for i in $(seq 11 17)
do
    printf "\033[${i};5H│"
done

for i in $(seq 11 17)
do
    printf "\033[${i};14H│"
done

for i in $(seq 11 14)
do
    printf "\033[${i};6Haa"
done

for i in $(seq 11 17)
do
    printf "\033[${i};12Haa"
done

printf "\033[14;8Haaaa"

printf "\033(B"
printf "\033[H\033[19;1H"
