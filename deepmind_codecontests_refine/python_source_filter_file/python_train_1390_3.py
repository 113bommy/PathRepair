n=int(input())
a={}
for i in range(n):
    a[input()]=[0,0,0]
k=n*(n-1)//2
for i in range(k):
    s=input().split(' ')
    c1,c2=s[0].split('-')
    g1,g2=map(int, s[1].split(':'))
    a[c1]=[a[c1][0],a[c1][1]+(g1-g2),a[c1][2]+g1]
    a[c2]=[a[c2][0],a[c2][1]+(g2-g1),a[c2][2]+g2]
    if g1>g2:
        a[c1][0]+=3
    elif g2>g1:
        a[c2][0]+=3
    else:
        a[c1][0]+=1
        a[c1][0]+=1

print("\n".join(sorted(y for x,y in sorted((y,x) for x,y in a.items())[n//2:])))
