a,b,c,d=map(int,input().split())
c=c/(3.14159265395*(a/2)**2)
if c<=d:
    print('No')
else:
    g=c-d
    print('Yes')
    print(b/g)