A, B, M = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
aaa = min(a) + min(b)
for k in range(M):
    x, y, c = map(int, input().split())
    ans = min(aaa, ((a[x - 1] + b[y - 1]) - c))
print(ans)