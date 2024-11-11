x=range(int(input()),0,-1)
P=[]
for _ in x:P+=[[int(i) for i in input().split()]]
P+=[P[0]]
for j in x:_+=P[j-1][0]*P[j][1]-P[j-1][1]*P[j][0]
print(_*0.5-1)