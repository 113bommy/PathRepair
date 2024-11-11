n,m= [int(i) for i in input().split()]
r=0
for i in range(n):
    a,b= [int(i) for i in input().split()]
    if a<=r:
        r=b
if(m<=r):
    print('YES')
else:
    print('NO')
