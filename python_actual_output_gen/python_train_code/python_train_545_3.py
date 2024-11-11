n = int(input())
a = [0] + list(map(int, input().split()))
b = [0] * (n + 1)

for i in range(n, 0, -1):
    for j in range(i, n + 1, i):
        b[i] ^= b[j]
    b[i] ^= a[i]

print(sum(b))
for i in range(1, n + 1):
    if b[i] == 1:
        print(b[i])