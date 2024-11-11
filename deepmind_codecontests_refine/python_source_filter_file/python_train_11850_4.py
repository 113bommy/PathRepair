N,M = map(int,input().split())

ds = set()
n = 1
while n*n <= M:
    if M%n==0:
        ds.add(n)
        ds.add(M//n)
    n += 1

ans = 1
for d in ds:
    if d <= N:
        ans = max(ans, d)
print(ans)