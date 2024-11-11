n,o,t=int(input()),0,0
for i in input().split():
    if i=='1':
        o+=1
    else:
        t+=1
if o-t>=0:
    print(t+(o-t)//3)
else:
    print(o//3)