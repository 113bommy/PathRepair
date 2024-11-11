from collections import deque
import sys
import math
input = sys.stdin.buffer.readline
# input = sys.stdin.readline
# x = list ( map(int,input().split()))
 
# n, m = map(int,input().split())
 
# for _ in range(m):
#     u, v ,d = map(int,input().split())
 
n= int(input())
x = list(map(int,input().split()))
# print(x)

# a = [0 for _ in range(n)]
# for i in range(n):
#     a[x[i]-1] = i+1
# print(a)
a=[]
b = [0 for i in range(n)]

for z in range(n):
    if x[z]==0:
        a.append(z+1)
    else:
        b[x[z]-1] =1
# print("a")
# print(a)# nemidan
# nemigiran
# print('b')
# print(b)
c = []
for z in range(n):
    if b[z] == 0:
        c.append(z+1)
# print('c')
# print(c)
a.sort()
c.sort()
# print(a)
# print(c)
for i in range(len(a)-1):
    if a[i] == a[i] :
        t = a[i]
        a[i] = a[i+1]
        a[i+1] =t
# print('a')
# print(a)
# print(c)

for i in range(len(a)):
    x[a[i]-1] = c[i]
# print(x)
print(' '.join(map(str,x)))