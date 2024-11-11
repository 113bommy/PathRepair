n,k=map(int,input().split())
rem=n//(2*k+1)
l=[(2*k+1)*i-k for i in range(1,rem+1) if (2*k+1)*i-k <=n]
now=0
if len(l)>0:
    now=n-l[-1]-k
x=k+1 - now
if x>0 and x<=k:
    l=[i-x for i in l]
    l.append(n)
elif x==0:
    l.append(n)
else:
    l.append(n-now+k)
if len(l)>0:
    print(len(l))
    print( *l)
elif len(l)==0 or k>n:
    print(1)
    print(max(1,n//2))
