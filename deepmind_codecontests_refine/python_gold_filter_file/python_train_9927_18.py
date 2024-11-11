n= int(input())
a=[int(x) for  x in input().split() ]
x=sorted(a)
an=0
for i in range(n):
    if a[i]!=x[i]:
        an+=1
if an<=2:
    print('YES')
else:
    print('NO')