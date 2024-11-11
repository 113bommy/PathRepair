n,m,k=map(int,input().split(' '))
a = list(map(int,input().split(' ')))
m-=1
i = m+1
one = -1
two = -1
ans = -1
while i<n:
    if a[i]<=k and a[i]!=0:
        one = abs(i-m)*10
        break
    i+=1
i = m-1
while i>0:
    if a[i]<=k and a[i]!=0:
        two = abs(i-m)*10
        break
    i-=1
if one!=-1:
    ans=one
if two!=-1:
    if ans==-1:
        ans=two
    else:
        ans = min(ans,two)
print(ans)
