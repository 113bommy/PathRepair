n = int(input())
a = [int(x) for x in input().split()]

b = []
b.append(1)

for i in range(1, n):
    if a[i] > 2 * a[i-1]:
        b.append(i)

b.append(n)
n = len(b)
m = 1
for i in range(1, n):
    if b[i] - b[i-1] > m:
        m = b[i] - b[i-1]

print(m)