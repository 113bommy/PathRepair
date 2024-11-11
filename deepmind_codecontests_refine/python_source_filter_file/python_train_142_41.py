#!/bin/python3

import sys


s=input()
j=s.replace('+'," ")
l=list(map(int,j.split()))
l.sort()
#print (l)
j=l
print (j[0],end="")
if(len(j)>2):
    for i in range(len(j)-2):
        print ("+"+str(j[i+1]),end="")
if(len(j)>2):
    print ("+"+str(j[len(j)-1]))

        
    


     
