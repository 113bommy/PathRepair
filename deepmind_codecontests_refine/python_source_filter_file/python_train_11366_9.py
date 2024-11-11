a,b,n =map(int,input().split())
t=1
def gys(m,k):
    q=1
    for i in range(1,min(m,k)):
        if i*(m//i)==m and i*(k//i)==k:
            q=i
    return(q)
while n>0:
    if t%2==1:
        n-=gys(a,n)
        t+=1
    else:
        n-=gys(b,n)
        t+=1
if t%2==1:
    print('1')
else:
    print('0')
    
