n, m, k = [int(x) for x in input().split()]
arr = []
o = 0
for i in range(m):
    arr.append(int(input()))
f = int(input())
f2 = []
for i in range(n -1, -1, -1):
    if (2 ** i) <= f:
        f -= (2 ** i)
        f2.append(True)
    else:
        f2.append(False)
for i in arr:
    z = 0
    for j in range(n - 1, -1, -1):
        if 2 ** j <= i:
            i -= 2 ** j
            if not f2[n - 1 - j]:
                z += 1
        else:
            if f2[n - j - 1]:
                z += 1
    if z <= k:
        o += 1