k2, k3, k5, k6 = map(int, input().split())
k5 = min(k5, k6)
if k2 >= k3 + k5:
    print(k5 * 256 + k3 * 32)
elif k2 >= k5:
    print(k5 * 256 + (k2 - k5) * 32)
else:
    print(256 * k5)
