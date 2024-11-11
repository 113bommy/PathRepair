N, x = map(int, input().split())
a = list(map(int, input().split()))

cnt = 0
for i in range(1, N):
    eat = max(a[i - 1] + a[i] - x, 0)
    cnt += eat
    a[i] -= max(eat,0)

print(cnt)
