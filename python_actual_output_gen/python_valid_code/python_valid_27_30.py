n=int(input())
cap=(2*n-2)
ans=2*(12*pow(4,(n-3)))
tmp=n-4
if tmp>=0:
    ans+=tmp*(36*pow(4,tmp))
print(ans)