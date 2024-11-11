n,m,z = map(int,input().split());j = min(n,m);c = max(n,m);n = j
ans = 0
for i in range(n, z+1, n):
    if i % c == 0:
        ans += 1
print(ans)