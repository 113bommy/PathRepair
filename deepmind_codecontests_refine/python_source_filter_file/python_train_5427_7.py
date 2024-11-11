from sys import stdin
from collections import deque
input=stdin.readline

n=int(input())
p=[0,0] + list(map(int,input().split()))
s=[0] + list(map(int,input().split()))
for i in range(1, n):
    if s[i] != -1:
        if s[p[i]] != -1:
            s[p[i]] = min(s[i], s[p[i]])
        else:
            s[p[i]] = s[i]
tot=s[1]
for i in range(2,n+1):
    if s[i] != -1:
        if s[i] > s[p[i]]:
            print(-1)
            exit()
        tot += s[i] - s[p[i]]
print(tot)
            
    

    
