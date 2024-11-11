import sys
import math
from collections import defaultdict,Counter

# input=sys.stdin.readline
# def print(x):
#     sys.stdout.write(str(x)+"\n")
from itertools import permutations
# sys.stdout=open("CP2/output.txt",'w')
# sys.stdin=open("CP2/input.txt",'r')

# m=pow(10,9)+7
n=int(input())
a=list(map(int,input().split()))
if n==1:
    print(a[0])
else:
    pref=[0]*n
    pref[0]=~a[0]
    suff=[0]*n
    suff[0]=~a[n-1]
    for i in range(1,n):
        pref[i]=pref[i-1]&~a[i]
        suff[n-i-1]=suff[n-i]&~a[i]
    ma=0
    ind=0
    for i in range(n):
        if i==0:
            d=a[i]&suff[i+1]
        elif i==n-1:
            d=a[i]&pref[i-1]
        else:
            d=a[i]&suff[i+1]&pref[i-1]
        if d>=ma:
            ma=d
            ind=i
    print(*a[ind:],*a[:ind])
# c=permutations(a)
# for i in c:
#     s=i[0]
#     for j in range(1,len(i)):
#         s=(s|i[j])-i[j]
#     print(i)
#     print(s)