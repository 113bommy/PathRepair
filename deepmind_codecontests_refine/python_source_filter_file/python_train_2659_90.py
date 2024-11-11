n, h = map(int, input().split())
f = list(map(int, input().split()))
w = 1
for i in range(0, n):
    if f[i] > h:
        w += 1
print(w)
