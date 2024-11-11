n, m, k = map(int, input().split())
a = sorted(list(map(int, input().split())), reverse=True)

max1 = a[0]
max2 = a[1]

blocks = m // (k+1)
res = blocks * (k*max1 + max2) + (m - blocks * (k+1)) * max2
print(res)
