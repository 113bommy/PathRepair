n, a, b = input().split()
n = int(n)
a = int(a)
b = int(b)

if a + b < n:
    print(b+1)
if a + b == n:
    print(b)
if a + b > n:
    print(n-a)