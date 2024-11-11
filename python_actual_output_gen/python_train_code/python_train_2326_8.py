n, a = map(int, input().split())
ar = list(map(int, input().split()))
a = a - 1
c = ar[a]
if n == 1:
    print(ar[0])
    exit(0)

b = min(n - a, a)
for i in range(1,b):
    c += ((ar[a - i] & ar[a + i]) << 1)
for i in range(a - b):
    c += ar[i]
for i in range(a + b, n):
    c += ar[i]
print(c)