from decimal import *
getcontext().prec = 50
p = input().split()

n = int(input())

c = input().split()





a='0'
for i in range(n-1,0,-1):
    a=str(Decimal(a)+Decimal(c[i]))
    a=str(Decimal('1')/Decimal(str(a)))

a=str(Decimal(a)+Decimal(c[0]))
b=str(Decimal(p[0])/Decimal(p[1]))


if(a==b):
    print("YES")
else:
    print("NO")
