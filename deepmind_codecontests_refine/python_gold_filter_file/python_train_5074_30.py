n,k=map(int,input().split())
a=[int(i) for i in input().split()]
ans=[]
o=0
e=0
for i in range(n):
    if a[i]%2==0:
        e+=1
    else:
        o+=1
    if e==o and i!=n-1 and abs(a[i]-a[i+1])<=k:
        ans.append(abs(a[i]-a[i+1]))
ans.sort()
c=0
s=0
for i in range(len(ans)):
    s+=ans[i]
    if s>k:
        break
    c+=1
print(c)