n, m, x, y = map(int, input().split())
a = list(map(int, input().split()))
b = list(map(int, input().split()))
i = 0
j = 0
l = []
while i < n and j < m:
        if b[j] < a[i]-x:
            j += 1
        elif b[j] > a[i]+x:
            i += 1
        else:
            l.append([i+1, j+1])
            i += 1
            j += 1
print(len(l))
for i in l:
    print(*i)
