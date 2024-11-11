l=input().split()
n=int(l[0])
x=int(l[1])
l=input().split()
li=[int(i) for i in l]
right=[0 for i in range(n)]
left=[0 for i in range(n)]
pref=[0 for i in range(n)]
pref[0]=li[0]
for i in range(1,n):
    left[i]=max(0,li[i-1]+left[i-1])
    pref[i]=pref[i-1]+li[i]
for i in range(n-2,-1,-1):
    right[i]=max(0,li[i+1]+right[i+1])
maxleft=0
ans=0
for i in range(n):
    if(i==0):
        maxleft=max(maxleft,left[i])
    else:
        maxleft=max(maxleft,left[i]-x*pref[i-1])
    ans=max(ans,right[i]+x*pref[i]+maxleft)
dp=[0 for i in range(n)]
dp[0]=li[0]
for i in range(1,n):
    dp[i]=max(dp[i-1]+li[i],li[i])
print(max(max(dp),ans))