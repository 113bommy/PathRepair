s=input()
n=len(s)
my=[0 for i in range(n)]
mn=[0 for i in range(n)]
for i in range(n):
    if s[i]>="a":
        mn[i]+=1
    else:
        my[i]+=1
    if i>0:
        mn[i]+=mn[i-1]
        my[i]+=my[i-1]
ans=10**6
my=[0]+my
mn=[0]+mn
for i in range(1,n):
    ans=min(ans,n-(my[i-1]+mn[-1]-mn[i-1]))
ans=min(ans,n-my[-1],n-mn[-1])
print(ans)
    
