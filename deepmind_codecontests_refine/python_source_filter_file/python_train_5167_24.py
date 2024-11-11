from collections import defaultdict
import math
from sys import stdin
index=0
string=stdin.readline().strip()
L=len(string)
letterList=[]
position=defaultdict(list)
output=L
for letter in string:
    letterList.append(letter)
    position[letter].append(index)
    index+=1
for key in position:
    position[key].insert(0,-1)
    position[key].append(L-1)
    lm=0
    for i in range(len(position[key])-1):
        length=position[key][i+1]-position[key][i]
        if length>lm:
            lm=length

    if lm<output:
        output=lm

print (output)


    