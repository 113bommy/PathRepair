a = [0 for i in range(301)]
cur = -1
n, p = [int(i) for i in input().split()]
for i in range(n):
    b = int(input())
    a[b % p] += 1
    if a[b % p] == 2:
        cur = i + 1
        break
print(cur)
