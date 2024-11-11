a,b,c,d=map(int,input().split())
c=c/(3.14159265395*(a/2)**2)
if c<=d:
    print('NO')
else:
    g=c-d
    print('YES')
    print(b/g)