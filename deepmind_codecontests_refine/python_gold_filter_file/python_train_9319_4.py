def f(j, k):
    q, e = 0, 0
    for i in range(j, k + 1):
        q |= a[i]
        e |= b[i]
    return q + e

# for i in range(0, int(input())):
n = int(input())
a = list(map(int, input().strip().split()))
b = list(map(int, input().strip().split()))

maximum = 0

for j in range(0, len(a)):
    for k in range(j, len(a)):
        maximum = max(maximum, f(j, k))
print(maximum)