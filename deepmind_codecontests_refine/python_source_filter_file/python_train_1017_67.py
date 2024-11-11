n,k,s=map(int,input().split())
a=[s]*k+[s+1]*(n-k)
print(*a)