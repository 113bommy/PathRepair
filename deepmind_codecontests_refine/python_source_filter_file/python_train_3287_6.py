def f(n, m, k, x):
    if x - n + k > 0 and x - k + 1 > 0:
        ans = ((x - 1) + (x - (n - k))) * (n - k) // 2 + ((x - 1) + (x - (k - 1))) * (k - 1) // 2 + x
    elif x - n + k <= 0 and x - k + 1 > 0:
        ans = ((x - 1) + (1)) * (n - k - (-(x - n + k) + 1)) // 2 + ((x - 1) + (x - (k - 1))) * (k - 1) // 2 + x + (-(x - n + k) + 1)
    elif x - k + 1 <= 0 and x - n + k > 0:
        ans = ((x - 1) + (x - (n - k))) * (n - k) // 2 + ((x - 1) + (1)) * (k - 1 - (-(x - k + 1) + 1)) // 2 + x + (-(x - k + 1) + 1)
    elif x - k + 1 <= 0 and x - n + k <= 0:
        ans = ((x - 1) + (1)) * (n - k - (-(x - n + k) + 1)) // 2 + ((x - 1) + (1)) * (k - 1 - (-(x - k + 1) + 1)) // 2 + x + (-(x - n + k) + 1) + (-(x - k + 1) + 1)
    if ans <= m:
        return True
    else:
        return False
    
n, m, k = map(int, input().split())
l = 1
r = 1000000000
while l + 1 < r:
    merg = (l + r) // 2
    if f(n, m, k, merg):
        l = merg
    else:
        r = merg
print(l)