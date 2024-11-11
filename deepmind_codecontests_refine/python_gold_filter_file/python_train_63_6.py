n,k = map(int ,input().split())

ans = 1
a = list(map(int ,input().split()))

for v in a:
    if k%v == 0:
        ans = max(ans, v)
print(k//ans)

