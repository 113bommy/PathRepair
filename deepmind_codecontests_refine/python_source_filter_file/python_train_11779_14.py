R =lambda:map(int, input().split())
x,y,z = R()
a,b,c = R()

A = a-x
if A>0:
    D = A+b-y
    M = D+c-z
    print('YES' if D>=0 and M>=0 else 'NO')
else:
    print('NO')