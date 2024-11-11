n,k = map(int,input().split())
h = sorted([int(input()) for _ in range(n)])
print(min(ans[j+k-1]-ans[j] for j in range(n-k+1)))