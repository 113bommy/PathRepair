n, m, k = map(int, input().split())
s = 0
l = list(map(int, input().split())) + [10**19]
t, c = 0, 1
for i in range(1, m+1):
    if (l[i] - t - 1) // k != (l[i-1] - t - 1) // k:
        s += 1
        t += c
        c = 1
    else:
        c += 1
print(s)