def gcd(a, b):
    a = int(a)
    b = int(b)
    if b == 0:
        return a
    return gcd(b, a % b)
n = int(input())
a = input().split()
for i in range(0, n):
    a[i] = int(a[i])
a = sorted(a)
d = 0
for i in range(1, n):
    d = gcd(d, a[i] - a[i - 1])
print(a)
print(int((a[n-1] - a[0]) / d - n + 1))