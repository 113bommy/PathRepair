from sys import stdin
p=int(stdin.readline().rstrip())
while p>0:
    n,s,t=map(int,stdin.readline().split())
    if n-s==n-t:
        print(n-s+1)
    else:
        print(max(n-s,n-t)+1)
    p-=1