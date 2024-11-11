import sys
input=sys.stdin.readline
for _ in range(int(input())):
    s=input(); n,k=map(int,input().split())
    a=list(map(int,input().split())); b=list(map(int,input().split()))
    sol=[1000000009]*n
    for x,y in zip(a,b):
        sol[x-1]=y
    j=0;
    for i in range(1,n):
        sol[i]=min(sol[i-1]+1,sol[i])
    for i in range(n-2,-1,-1):
        sol[i]=min(sol[i+1]+1,sol[i])
    print(*sol)
