import math

def compute(l, n):
    l2 = math.ceil(n / l)
    return 2 * l + 2 * l2

n = int(input())

best = 9999999999
for i in range(1, n):
    best = min(best, compute(i, n))
print(best)
