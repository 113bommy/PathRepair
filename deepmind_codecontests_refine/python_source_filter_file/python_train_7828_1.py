input()
a={}
for x in list(map(int,input().split())):
    if x in a:
        a[x]+=1
    else:
        a[x]=1
ans,flag=0,False
for x in a:
    if x>=4:
        ans+=(a[x]//4)
        a[x]%=4
    if a[x]>1:
        if flag==True:
            ans+=1
        flag=not flag
print(ans)
