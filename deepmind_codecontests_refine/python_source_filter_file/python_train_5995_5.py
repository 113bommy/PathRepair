n, k, x = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
p1, i =  [], 0
while i < k:
    a.sort()
    p1 = a.copy()
    for j in range(0, n, 2):
        a[j] = a[j] ^ x
    if n * k > 50000 and min(a) == p1[0] and max(a) == p1[-1]:
        break
    i += 1
print(max(a), min(a))