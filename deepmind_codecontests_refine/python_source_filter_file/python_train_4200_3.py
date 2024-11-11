n, m, x, y = map(int,input().split())
a = list(map(int,input().split()))
b = list(map(int,input().split()))

c = []
j = 0
for i in range(n):
    while j < m and b[j] >= a[i] +y:
        if a[i] - x <= b[j]:
            j += 1
            c += [(i+1, j)]
            break
        j += 1
print(len(c))
for i, j in c:
    print(i, j)
