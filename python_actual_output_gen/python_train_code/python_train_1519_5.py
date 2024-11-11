
__author__ = 'Esfandiar'
__attention__ = 'This code written by analysing cs1g code'
import sys
input=sys.stdin.readline
n = int(input())
a = list(map(int,input().split()))
a1,b1 = sum(a[1::2]),sum(a[2::2])
res = a1 == b1
for i in range(n-1):
    yy = a[i] - a[i+1]
    if i%2==0:a1+=yy
    else:b1+=yy
    res+= a1==b1
print(res)
'Thanks a lot csg1'