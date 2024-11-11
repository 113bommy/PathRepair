n, z = map(int, input().split(' '))
x = sorted(map(int, input().split(' ')))
l, r = 0, n//2
res = 0
while l < n//2 and r < n:
    if x[l] + x[r] >= z:
        res += 1
        l += 1
    r += 1
print(res)