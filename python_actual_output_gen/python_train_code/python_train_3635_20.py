k2, k3, k5, k6 = map(int, input().split())
n256 = min(k2, min(k5, k6))
n32 = max(k3, k2 - n256)
print(32 * n32 + 256 * n256)
