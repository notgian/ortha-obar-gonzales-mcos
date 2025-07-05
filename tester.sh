#!/bin/bash

inputdir="./inputdata"
outputdir="./output"

inputfiles="$(ls $inputdir | grep -Eo "n[0-9]+")"

echo "" > "./times/slowtimes.txt"
echo "" > "./times/fasttimes.txt"

for file in ${inputfiles[@]}; do
    echo "$file" >> "./times/slowtimes.txt"
    echo "$file" >> "./times/fasttimes.txt"
    
    ./main1 <<< "$inputdir/$file.txt $outputdir/$file" | grep -Eo '[0-9]+.[0-9]+ms' >> "./times/slowtimes.txt"
    ./main2 <<< "$inputdir/$file.txt $outputdir/$file" | grep -Eo '[0-9]+.[0-9]+ms' >> "./times/fasttimes.txt"
    
done

echo "DONE!"
