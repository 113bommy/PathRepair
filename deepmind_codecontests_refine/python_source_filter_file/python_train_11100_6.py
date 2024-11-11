n, k = map(int, input().split())
L = list(map(int, input().split()))
d = {}
mx = -500
for i in range(n):
    mx = max(mx, L[i])
    if mx in d:
        d[mx] += 1
    else:
        d[mx] = 1
    if d[mx] == k:
        print(mx)
        exit()
print(mx) 