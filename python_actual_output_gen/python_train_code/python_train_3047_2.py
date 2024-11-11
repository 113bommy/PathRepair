res = []
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    x = (k % 3 == 0)
    y =  (n % 3 == 0)
    z = (n % (k + 1) != k)
    w = (n % (k + 1) % 3 == 0)
    if (not x and y) or (x and y and z and w):
        res.append('Bob')
    else:
        res.append('Alice')
print('\n'.join(res))
