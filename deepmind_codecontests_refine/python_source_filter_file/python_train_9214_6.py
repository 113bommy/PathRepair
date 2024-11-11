#!/usr/bin/python3.5

n=int(input())
s=input()
i,e=0,0
while i<n:
    k=i+1
    while k<=n:
        c,d=0,0
        for j in range(i,k):
            if s[j]=='U':
                c+=1
            elif s[j]=='D':
                c-=1
            elif s[j]=='R':
                d+=1
            else:
                d-=1
        if c==0 and c==0:
            e+=1
        k+=1
    i+=1

print(e)
