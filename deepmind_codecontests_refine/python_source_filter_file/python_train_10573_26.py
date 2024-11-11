k2, k3, k5, k6 = map(int, input().split())
b = min(k2, k5, k6)
print(256*b + 32*(0 if b == k2 else min(k2, k3)))