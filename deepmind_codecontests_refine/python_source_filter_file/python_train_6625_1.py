from math import *
from sys import stdin, stdout, setrecursionlimit
from bisect import *
from collections import *
input = lambda: stdin.readline().strip()
print = stdout.write

s1=input()
s2=input()

al=defaultdict(list)
count=1;index=0;count=0

for i in range(len(s1)):
    al[s1[i]].append(i)

for i in range(len(s2)):
    if(len(al[s2[i]])==0):
        print(str(-1))
        exit()

for i in range(len(s2)):

    r=bisect_left(al[s2[i]],index)
    if(r==len(al[s2[i]])):
        count+=1
        index=al[s2[i]][0]+1
    else:
        index=al[s2[i]][r]+1

print(str(count))