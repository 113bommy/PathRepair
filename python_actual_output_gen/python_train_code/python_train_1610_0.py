# Don't wait for opportunity. Create it. Unknown
# by : Blue Edge - Create some chaos
n,b=map(int,input().split())
a=list(map(int,input().split()))
c=[]
mini=4000
for x in a[:-1]:
    mini=min(x,mini)
    c.append(mini)

maxi=0
i=n-2
ans=0
for x in a[-1:0:-1]:
    maxi=max(maxi,x)
    # print(maxi,c[i])
    ans=max(ans,b+max(0,(b//c[i])*(maxi-c[i])))
    # print(ans)
    i-=1

print(ans)
