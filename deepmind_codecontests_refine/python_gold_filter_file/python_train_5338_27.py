n=int(input())
a=list(map(int , input().split()))
ans=[0]*n
a.sort()
ind=n-1
ind1=0
c=0
for i in range(n):
    if i%2==0:
        ans[i]=a[ind]
        ind-=1
    else:
        ans[i]=a[ind1]
        ind1+=1
for i in range(1,n-1):
    if ans[i]<ans[i-1] and ans[i]<ans[i+1]:
        c+=1
print(c)
print(*ans)


