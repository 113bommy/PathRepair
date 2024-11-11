import sys

n = int(sys.stdin.readline().strip())
a = list(map(int, sys.stdin.readline().strip().split()))
b = a[:]
C = [0] * n
x = [0] * n
for i in range (0, 40):
    for j in range (0, n):
        x[j] = b[j] % 2
        b[j] = b[j] // 2
    if sum(x) == 1:
        for j in range (0, n):
            if x[j] == 1:
                C[j] = C[j] + 1
l = C.index(max(C))
print(" ".join(list(map(str, [a[l]]+a[0:l]+a[l+1:]))))
        