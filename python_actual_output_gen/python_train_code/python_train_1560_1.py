import sys
q=int(input())
mi=0
ma=0
for j in range(q):
    a,b,c=map(str,sys.stdin.readline().split())
    r=int(b)
    s=int(c)
    if a=='+':
        mi=max(mi,min(r,s))
        ma=max(mi,max(r,s))
    else:
        p=min(r,s)
        q=max(r,s)
        #print(p,q,mi,ma)
        if mi<=p and ma<=q:
            print('YES')
        else:
            print('NO')