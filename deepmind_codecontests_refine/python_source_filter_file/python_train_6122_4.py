n=int(input())
s=list(map(int,input().split()))
t=[0]*n
for i in range(n):
    if i==n-1-i:
        continue
    t[i]+=s[i]+s[n-1-i]
ans=0
for c in range(1,n//2):
    num=0
    s_max=0
    if (n-1)%c==0:
        for k in range((n//2)//c+1):
            if n//2<=c*k:
                break
            num+=t[c*k]
            s_max=max(s_max,num)
    else:
        for k in range((n-1)//c+1):
            num+=t[c*k]
            s_max=max(s_max,num)
    ans=max(ans,s_max)

print(ans)