n = int(input())
nn = n
f = lambda x, y: x + y * nn
g = lambda x: x if x % 2 == 1 else x + nn

# 2の累乗はむり
b = bin(n)
if b.count('0') == len(b) - 2:
    print('No')
    exit(0)

ret = [
    [f(1, 0), f(2, 0)],
    [f(2, 0), f(3, 0)],
    [f(3, 0), f(1, 1)],
    [f(1, 1), f(2, 1)],
    [f(2, 1), f(3, 1)],
]

if n % 2 == 0:
    p = 2 ** (len(b) - 3)
    q = n ^ 1 ^ p
    ret.append([g(p), f(n, 0)])
    ret.append([g(q), f(n, 1)])
    n -= 1

# nは奇数
while n > 3:
    ret.append([f(n - 1, 0), f(n, 0)])
    ret.append([f(n, 0), f(1, 1)])
    ret.append([f(1, 1), f(n - 1, 1)])
    ret.append([f(n - 1, 1), f(n, 1)])
    n -= 2

print('Yes')
for x, y in ret:
    # x = x if x <= nn else x - nn
    # y = y if y <= nn else y - nn
    print(x, y)
