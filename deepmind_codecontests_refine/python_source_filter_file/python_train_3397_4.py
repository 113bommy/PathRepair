from sys import stdin, stdout
import sys
INF=1e11
import bisect
def get_int(): return int(stdin.readline().strip())
def get_ints(): return map(int,stdin.readline().strip().split()) 
def get_array(): return list(map(int,stdin.readline().strip().split()))
def get_string(): return stdin.readline().strip()
def op(c): return stdout.write(c)
from collections import defaultdict 
import math
#for _ in range(int(stdin.readline())):
d=defaultdict(float)
n,m,X=get_ints()
arr=[]
pos=[]
for i in range(n):
    s=get_string()
    arr.append(s)
    for j in range(len(s)):
        if s[j]=="S":
            pos.append([i,j])
        d[arr[i][j]]=INF
for i in range(n):
    for j in range(m):
        if arr[i][j]=="S":
            continue
        dis=INF
        for x in range(len(pos)):
            dis=min(dis,math.sqrt((i-pos[x][0])**2 + (j-pos[x][1])**2))
        d[arr[i][j]]=min(d[arr[i][j]],dis)
q=get_int()
s=get_string()
ans=0
f=0
for ch in s:
    if ch.isupper():
        ch=ch.lower()
        if len(pos)==0:
            print(-1)
            f=1
            break
        if ch not in d:
            print(-1)
            f=1
            break
        if d[ch]>x:
            ans+=1
    else:
        if ch not in d:
            print(-1)
            f=1
            break
if f==0:
    print(ans)