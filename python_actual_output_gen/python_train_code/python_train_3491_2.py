n,m,k=[int(i) for i in input().split()]
a=[int(i) for i in input().split()]
a1=[0]*(n+1)
i=1
for j in a:
    a1[j]=j
    i+=1

b=[int(i) for i in input().split()]
ans=0
for i in b:
    index=a1[i]
    ans+=(index-1)//k+1
    if index>1:
        tmp1=a[index-1]
        tmp0=a[index-2]
        a[index-1],a[index-2]=tmp1,tmp0
        a1[tmp0],a1[tmp1]=index,index-1

print(ans)
