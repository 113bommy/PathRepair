n = int(input())
a = [int(x) for x in input().split()]

ex = []
ex.append(1)
mx = 0

for i in range(1, n):
    if a[i] > a[i - 1]:
        ex.append(ex[-1] + 1)
    else:
        ex.append(1)
    mx = max(mx, ex[-1])

print(mx)