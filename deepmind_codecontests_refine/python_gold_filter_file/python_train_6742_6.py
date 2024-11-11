def doit(n, k, l, a):
    m = n * k
    a.sort()
    hen = 1
    tai = m
    while ((hen < m) and (a[hen] <= a[0] + l)):
        hen += 1
    if (hen < n):
        return 0
    for i in range(n):
        tai -= k
        if (hen > tai):
            break
        hen -= 1
        a[hen], a[tai] = a[tai], a[hen]
    temp = 0
    for i in range(n):
        temp += a[i * k]
    return temp


n, k, l = input().split()
a = input().split()
for i in range(len(a)):
    a[i] = int(a[i])
print(doit(int(n), int(k), int(l), a))