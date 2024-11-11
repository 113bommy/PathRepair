n, k = map(int, input().split())
a = [int(i) for i in input().split()]
b = []
c = []
for i in range(len(a)):
    if not(a[i] in b) :
        b.append(a[i])
        c.append(i)
if len(b) >= k:
    print('YES')
    for i in c[:k]:
        print(i + 1, end=' ')
else:
    print('NO')