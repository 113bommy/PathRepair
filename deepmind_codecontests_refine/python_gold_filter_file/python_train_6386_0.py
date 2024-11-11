n=int(input())
l=list(map(int,input().split()))
i=1
ll=l[0]
while(i<n-1):
    if (l[i]>l[i+1]):
        if l[i]<ll:
            ll=l[i]
        i+=1
    else:
        if l[i+1]<ll:
            ll=l[i+1]
        i+=2
if l[n-1]<ll:
    ll=l[n-1]
print(ll)