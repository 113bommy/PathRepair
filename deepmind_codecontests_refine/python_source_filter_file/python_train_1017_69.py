n,k,s = map(int,input().split())
ans = [s]*k+[0]*(n-k)
print(*ans)