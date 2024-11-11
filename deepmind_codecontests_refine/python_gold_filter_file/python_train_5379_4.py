s=list(input())
n=len(s)
if n==1:
    print(-1)
    exit(0)
ans=2e9
for i in range(n):
    for j in range(i+1,n):
        s1=s[:]
        cnt=0
        i1,j1=i+1,j+1
        while j1<n:
            s1[j1-1],s1[j1]=s1[j1],s1[j1-1]
            j1+=1
            cnt+=1
        while i1<n-1:
            s1[i1-1],s1[i1]=s1[i1],s1[i1-1]
            i1+=1
            cnt+=1
        k=0
        while k<n and s1[k]=='0':
            k+=1
        if int("".join(s1))%25==0:
            ans=min(ans,cnt+k)
        s1[n-1],s1[n-2]=s1[n-2],s1[n-1]
        if int("".join(s1))%25==0:
            ans=min(ans,cnt+k+1)
if ans==2e9:
    print(-1)
else:
    print(ans)