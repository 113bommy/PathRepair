n,k=map(int,input().split())
s=list(input())
cnt=0
ans=0
j=0
for i in range(n):
    if s[i]=="0":
        if i==0 or s[i-1]=="1":
            cnt+=1
    if cnt>k:
        while s[j]=="1":
            j+=1
        while s[j]=="0":
            j+=1
        cnt-=1
    ans=max(ans,i-j+1)

print(ans)