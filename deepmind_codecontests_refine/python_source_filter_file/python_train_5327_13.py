from sys import stdin
t=int(stdin.readline().rstrip())
while t>0:
    n,s,t=map(int,stdin.readline().split())
    if n-s==n-t:
        print(n-s+1)
    else:
        print(max(n-s,n-t)+1)
    t-=1