#!/usr/bin/python3.5
s=input()
m=1000000007
p=0
k=0

for i in s:
    if i=='a':
        k<<=1
        k%=m
    else:
        p+=k;
        p%=m
print(p)