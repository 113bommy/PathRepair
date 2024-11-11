import sys
input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))
if n == 1:
    print(1, 1)
    print(-a[0])
    print(1, 1)
    print(0)
    print(1, 1)
    print(0)
    exit()

inv = 0
for i in range(1, n):
    if (n - 1) * i % n == 1:
        inv = i
        break

print(1, 1)
print(-a[0])
a[0] = 0
print(2, n)
op = []
for i in range(1, n):
    x = -a[i] * inv % n* (n - 1)
    op.append(x)
    a[i] += x
print(*op)
print(1, n)
op = [-x for x in a]
print(*op)