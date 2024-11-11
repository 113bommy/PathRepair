n = int(input())
p = [int(input()) for _ in range(n)]
pi = [(x-1, i) for i, x in enumerate(p)]
pi.sort()
pi.append((n, -1))

l, mxl = 0, 0
for i, x in pi:
    if x < pi[i-1][1]:
        mxl = max(l, mxl)
        l = 0
    l += 1

print(n - mxl)
