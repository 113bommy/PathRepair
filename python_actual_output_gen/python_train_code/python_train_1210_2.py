n = int(input())
a = sorted(list(map(int, input().split())))
x = 0
for i in a:
    x ^= i
for i in range(n):
    a[i] ^= x
print(*a)