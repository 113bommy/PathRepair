n,z = map(int,input().split())
A = list(map(int,input().split()))
A.sort()

ans = 0
vis = [False]*n
j = 0

for i in range(n):
    if vis[i]:
        continue

    while j < n and A[j] - A[i] < z:
        j += 1

    if j == n:
        break

    vis[j] = True
    j += 1
    ans += 1

print(ans)
