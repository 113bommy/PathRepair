n = int(input())
maxv = -2 * 10 ** 9
minv = 2 * 10 ** 9
for i in range(1, n):
    v = int(input())
    maxv = max(maxv, v - minv)
    minv = min(minv, v)
print(maxv)