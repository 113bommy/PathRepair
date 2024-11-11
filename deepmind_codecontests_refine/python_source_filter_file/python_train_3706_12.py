def IsPrime(n):
    d = 2
    while n % d != 0:
        d += 1
    return d == n
l=0
b,m=map(int,input().split())
for i in range(b,m):
    if IsPrime(i)==True:
        l+=1
if l==0 and IsPrime(m)==True:
    print('YES')
else:
    print('NO')
