s=input()
t=input()
n,m=len(s),len(t)
l,r,j=[0]*m,[0]*m,0
for i in range(m):
    while s[j]!=t[i]:
        j+=1
    l[i]=j
    j+=1
j=n-1
for i in range(m-1,-1,-1):
    while s[j]!=t[i]:
        j-=1
    r[i]=j
    j-=1
ans=max(0,r[0],n-1-l[-1])
for i in range(m-1):
    ans=max(ans,r[i+1]-l[i])
print(ans)