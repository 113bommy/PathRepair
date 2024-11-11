n, m = [int(i) for i in input().split()]
c = 10**250
e = 0
for i in range(n//9 + 1):
    e = e*10 + 9
a = c - e
b = e
print(a, end=' ')
print(b)