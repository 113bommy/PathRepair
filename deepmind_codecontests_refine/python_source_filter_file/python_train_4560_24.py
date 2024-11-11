#144_E
n, k = map(int, input().split())
a = sorted(list(map(int,input().split())))
f = sorted(list(map(int,input().split())))[::-1]

l, r = -1, 200000
while r - l > 1:
    x = (r + l) // 2
    
    res = 0
    for i in range(n):
        res += max(0, a[i] - x // f[i])
    
    if res > k:
        l = x
    else:
        r = x
print(r)