n = int(input())
a = [int(i) for i in input().split()]
m = int(input())
b = [int(i) for i in input().split()]
if sum(a) != sum(b):
    print(-1)
else:
    i = 0
    j = 0
    c1 = a[0]
    c2 = b[0]
    count = 0
    while i < n or j < m:
        if c1 == c2:
            count += 1
            i += 1
            j += 1
            if i < n and j < n:
                c1 += a[i]
                c2 += b[j]
        elif c1 < c2:
            i += 1
            if i < n:
                c1 += a[i]
        elif c2 < c1:
            j += 1
            if j < m:
                c2 += b[j]
    print(count)