n,k = map(int,input().split())
l = list(map(int,input().split()))
c=0
for i in range(1,n):
    if l[i-1]>=l[i]:
        x=((l[i-1]-l[i])//k+1)*k
        print(x,l[i],l[i-1],end=" ")
        l[i]=l[i]+x
        print(l[i])
        c=c+(x//k)
#print(l)
print(c)
        