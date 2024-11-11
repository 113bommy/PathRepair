n = int(input())
a = list(map(int, input().split()))

for i in range(n):
    if not (a[i] & 1):
        a[i] -= 1

print(*a)
