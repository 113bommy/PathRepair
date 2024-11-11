# http://codeforces.com/problemset/problem/735/B
get=lambda:list(map(int,input().split()))
n,N1,N2=get()
l=get()

l.sort(reverse=True)

if N1<N2:
    c1=l[:N1]
    c2=l[N1:N2+N1]
    ans=sum(c1)/N1+sum(c2)/N2
else:
    c2=l[:N2]
    c1=l[N2:N2+N1]
    ans=sum(c1)/N1+sum(c2)/N2
print(c1,c2)
print("%.10f"%(ans))
    
