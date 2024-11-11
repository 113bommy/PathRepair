n,m,k=map(int,input().split())
a=list(map(int,input().split()))
a.sort(reverse=True)

if len(a)==1:
    print(a[0]*k)
else:
    ans=0
    ans+=(a[0]*k+a[1])*(m/(k+1))
    if(m%(k+1)!=0):
        ans+=a[0]*(m%(k+1))
    print(int(ans))
    