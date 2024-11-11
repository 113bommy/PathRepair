n=int(input())
a=list(map(int,input().split()))
ans=0
c=0
di={}
for i in range(n):
    if(a[i] not in di):
        c+=1
        di[a[i]]=1
    else:
        c-=1
        del di[a[i]]
    ans=max(ans,c)
print(ans)        