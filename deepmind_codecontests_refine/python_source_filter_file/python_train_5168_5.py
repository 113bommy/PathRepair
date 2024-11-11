n = int(input())
a = [int(i) for i in input().split()]

m = 1000000000000000
lastm = None
r = 1000000000000000
for i in range(n):
    if a[i] < m:
        m = a[i] 
        lastm = i
        r = 1000000000000000
    elif a[i] == m:
        tr = i - lastm
        if tr < r:
            r = tr
            lastm = i


print(r)
