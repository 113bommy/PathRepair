n=int(input())

a=list(map(int,input().split()))
o=a.count(1)
ans=0
for i in range(n):
    c=o
    for j in range(i,n):
        if(a[j]==0):
            c+=1
        else:
            c-=1
        ans=max(ans,c)
        
print(ans)