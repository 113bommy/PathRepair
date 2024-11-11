a = [int(x) for x in input().split()]
k,m = map(int, input().split())

a1 = [int(y) for y in input().split()]
a1.sort()
a11 = a1[:k]
a2 = [int(z) for z in input().split()]
a2.sort()
a21 = a2[len(a2)-m:]

if a11[-1]<a21[0]:
    print('YES')
else:
    print('NO')

