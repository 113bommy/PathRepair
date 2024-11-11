import math
n = int(input())
ints = list(map(int, input().split()))


if (n == 1): 
    print(1, 1)
    print(0)
else:
    print(1, n - 1)
    res = [None for i in range(n - 1)]
    for i in range(n - 1):
        val = abs(ints[i] % n) * (n - 1)
        res[i] = int(math.copysign(val, ints[i]))
        ints[i] += res[i]
    print(" ".join(map(str, res)))

print(n, n)
print(n - ints[n - 1])
ints[n - 1] += n - ints[n - 1]

print(1, n)
for i in range(n):
    ints[i] *= -1
print(" ".join(map(str, ints)), end=" ")

