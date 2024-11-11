import sys
from collections import *
input = sys.stdin.readline
s = input()[:-1]
n = len(s)
a,b = [int(x) for x in input().split()]
y  = [0]*(n-1)
num = 0
t = 1
for i in range(n-1,0,-1):
    num = (num + (int(s[i])*t)%b)%b
    t = (t*10)%b
    if s[i]=='0':
        y[i-1]=1
    else:
        y[i-1]=num
res = 0
num = 0
for i in range(n-1):
    num = ((num*10)%a+int(s[i])%a)%a
    if num==0 and y[i]==0 and s[i+1]!='0':
        res = 1
        print("YES")
        print(s[:i+1])
        print(s[i+1:])
        break
if res == 0:
    print("NO")
        