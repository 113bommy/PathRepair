c = -9999999
n, k = map(int, input().split())
for i in range(n):
    a, b = map(int, input().split())
    if b > k:
        a -= (b - k)
    c = max(a, c)
print(c)

# CodeForcesian
# ♥
# Sad
