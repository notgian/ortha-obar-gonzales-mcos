#!/bin/bash

inputdir="./inputdata"
outputdir="./output"

inputfiles="$(ls $inputdir | grep -Eo "n[0-9]+")"

echo "" > "./times/slowtimes.txt"
echo "" > "./times/fasttimes.txt"

for file in ${inputfiles[@]}; do
    echo "$file" >> "./times/slowtimes.txt"
    echo "$file" >> "./times/fasttimes.txt"
    for i in $(seq 1 5); do
        ./main1 <<< "$inputdir/$file.txt $outputdir/$file-$i.txt" | grep -Eo '[0-9]+.[0-9]+ms' >> "./times/slowtimes.txt"
        ./main2 <<< "$inputdir/$file.txt $outputdir/$file-$i.txt" | grep -Eo '[0-9]+.[0-9]+ms' >> "./times/fasttimes.txt"
    done
done

echo "DONE!"
