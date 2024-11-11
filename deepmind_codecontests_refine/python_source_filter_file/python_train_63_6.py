n,k = map(int ,input().split())

ans = 101;
a = list(map(int ,input().split()))

for v in a:
    if k%v == 0:
        ans = min(ans, v)
print(k//ans)

