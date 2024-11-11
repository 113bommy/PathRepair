import sys
n,x=map(int,input().split())
t=list(map(int,input().split()))
if sum(t)+len(t)-1<=x:
    print('YES')
else:
    print('NO')