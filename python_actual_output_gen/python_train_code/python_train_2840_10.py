#!/usr/bin/env pypy
#for t in range(int(input())):
h,m=[int(x) for x in input().split(":")]
n=int(input())

m+=n%60
if m>60:
    m-=60
    h+=1
if m<10:
    m='0'+str(m)
h+=n//60
if h>23:
    h%=24
if h<10:
    h='0'+str(h)
print("{}:{}".format(h,m))






