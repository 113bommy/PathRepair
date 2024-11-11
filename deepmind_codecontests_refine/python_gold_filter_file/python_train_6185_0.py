def gcd(a, b):
    if (a < b):
        a, b = b, a
    if (b == 0):
        return a
    return gcd(a % b, b)


n = int(input())
a = list(map(int, input().split()))
ma = max(a)
mi = min(a)
c = a[0]
for i in a[1:]:
    c = gcd(c, i)
ma //= c
if (ma - n) % 2 == 1:
    print("Alice")
else:
    print("Bob")