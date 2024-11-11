t, s, q = [int(x) for x in input().split()]
res = 0
while (s < t):
    s = s * q
    res += 1
print(res)