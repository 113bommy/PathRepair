k = int(input())
n = 50
m = k % n
q = k // n

a = [n - 3 + q - m] * n
for i in range(m):
    a[n - 1 - i] += n

print(n)
print(*a)
