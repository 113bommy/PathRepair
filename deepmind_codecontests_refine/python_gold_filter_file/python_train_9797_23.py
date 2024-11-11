from math import ceil
n, k = map(int, input().split())
step = 2 * k + 1
m = ceil(n / step)
a = (m * step - n) // 2
b = k - a + 1
print(m)
print(' '.join([str(i) for i in range(b,n + 1,step)]))

















