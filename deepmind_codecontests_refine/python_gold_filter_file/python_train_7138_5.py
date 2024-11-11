s,n,a=0,int(input()),0
for i in range(n):
    t,d=map(str,input().split());t=int(t)
    if not a and d[0]!="S"or a==20000and d[0]!="N"or d[0]=="N"and a-t<0 or d[0]=="S"and a+t>20000:s=1;break
    a+=0if d not in "NorthSouth"else t if d[0]=="S"else-t
print("YES" if not (s or a) else "NO")