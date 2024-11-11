n,k,s=map(int,input().split())
x=10**9
if s==x:x=10**8
a=[s]*k+[x]*(n-k)
print(*a)