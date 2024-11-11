n = int(input())
a = list(map(int, input().split()))
z = sum(a)
ln = []
x = 0
for i in range(1, n):
    x += a[i]
    ln.append(abs(z - 2 * x))
print(min(ln))