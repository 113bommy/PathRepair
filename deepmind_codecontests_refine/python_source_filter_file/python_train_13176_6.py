n,m=[int(i) for i in input().split()]
p,e=set([]),set([])
for i in range(n):
    p.add(input())
for i in range(m):
    e.add(input())
tyo=p&e
n-=len(tyo)
m-=len(tyo)

if n-len(tyo)%2>m:
    print('YES')
else:
    print('NO')