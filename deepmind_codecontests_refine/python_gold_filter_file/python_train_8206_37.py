n = int(input())
a = list(map(int, input().split()))
z = sum(a)
ln = []
x = 0
for i in range(n - 1):
    x += a[i]
    ln.append(abs(z - 2 * x))
print(min(ln))