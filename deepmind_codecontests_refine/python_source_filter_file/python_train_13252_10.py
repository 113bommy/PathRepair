import math
from collections import defaultdict
from sys import stdin
input=stdin.readline
n,m=map(int,input().split())
lcm=30030
mat=[]
for i in range(n):
  mat.append(list(map(int,input().split())))
for i in range(n):
  for j in range(m):
    if (i+j)%2==0:
      print(lcm,end=' ')
    else:
      print(lcm+mat[i][j]**4,end=' ')
  print()

  
