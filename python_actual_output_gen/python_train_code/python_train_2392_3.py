n, m = [int(i) for i in input().split()]
lst = [0] * n
for i in range(m):
    a, b = [int(x) for x in input().split()]
    for j in range(a - 1, b):
        lst[j] += 1
for i in range(n):
    if lst[i] != 1:
        print(i + 1, lst[i])
        break
print("OK")

