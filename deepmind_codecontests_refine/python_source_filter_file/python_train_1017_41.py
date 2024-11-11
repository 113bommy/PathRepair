n,k,s=map(int,input().split())

lst=[s]*k+[s+1]*(n-k)
print(*lst)