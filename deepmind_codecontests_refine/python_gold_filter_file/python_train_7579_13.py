n,k = map(int,input().split())
h = sorted([int(input()) for _ in range(n)])
print(min(h[j+k-1]-h[j] for j in range(n-k+1)))