#!/bin/bash
# Read from the file file.txt and print its transposed content to stdout.
awk '{
  for( i=1; i <= NF; ++i ){
    row[i] = ( row[i] == "" ? $i : row[i]" "$i );
  }
}
END{
  for( i=1; row[i] != ""; ++i){
    print row[i];
  }
}' file.txt

# I had tried the following memory limit exceed solutions before the solution above was accepted:

# 1 awk
#for(( i=1; i <= $(head -n 1 file.txt | wc -w);i++ )); do awk '{print $'$i'}' file.txt | tr '\n' ' '; echo; done

# 2 bash
#for(( i=1; i <= $(head -n 1 file.txt | wc -w);i++ )); do cut -d ' ' -f$i file.txt | tr '\n' ' '; echo; done

# 3 bash
#filename=file.txt
#ncols=$(head -n 1 $filename | wc -w)
#for((i=1;i<=ncols;++i)); do
#  row=""
#  while read -r line 
#  do
#    row="$row $(echo $line | cut -d ' ' -f$i)"
#  done < $filename
#  echo $row
#done
