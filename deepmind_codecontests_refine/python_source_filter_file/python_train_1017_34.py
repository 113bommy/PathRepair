n, k, s= map(int,input().split())

ans = [s]*k+[1]*(n-k)

print(*ans)