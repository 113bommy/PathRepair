n, m = map(int, input().split())
a = list(map(int, input().split()))
a.sort()
bc = [map(int, input().split()) for _ in range(m)]

bc.sort(reverse=True, key=lambda x:x[1])

i = 0
for b,c in bc:
    for j in range(i, min(n, i+b)):
        if a[j]<c:
            a[j] = c
    i = i+b
print(sum(a))
