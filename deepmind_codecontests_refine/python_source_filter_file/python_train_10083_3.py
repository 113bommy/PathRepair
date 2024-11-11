n,a,b = map(int,input().split())
X = list(map(int,input().split()))
pos = X[0]
ans = 0
for i in range(1, n):
    ans += min(b, X[i] - pos)
    pos = X[i]
print(ans)