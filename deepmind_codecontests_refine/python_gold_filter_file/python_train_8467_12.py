def binSearch(a, x):
    l = -1
    r = len(a)
    while l < r - 1:
        m = (r + l) // 2
        if a[m] < x:
            l = m
        else:
            r = m
    return r

a = [0] * 47
a[1] = 1
a[2] = 1
for i in range(3, 47):
    a[i] = a[i-1]+a[i-2]
n = int(input())
i = binSearch(a, n)
if (n == 0):
    print(0, 0, 0)
elif (n == 1):
    print(0, 0, 1)
else:
    print(0, a[i - 2], a[i - 1])
