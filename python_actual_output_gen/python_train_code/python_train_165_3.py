n = int(input())
l = 0
r = 0
for i in range(n):
    a, b = input().split()
    a = int(a)
    b = int(b)
    if a == 1:
        l += 1
    if b == 1:
        r += 1

print(min(l, n-1) + min(r, n - r))