__author__='Walnut'
import math
import copy

s1=input()#.split()
s2=input()#.split()
s=[]
#print(len(s1))
for i in range(len(s1)):
    if s1[i]!=s2[i]:
        s.append('1')
    else:
        s.append('0')
print(''.join(s))