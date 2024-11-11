n,l=map(int,input().split())
a=list(map(int,input().split()))
cnt=0
flag=False
for i in range(0,n-1):
    if not flag:
        if a[i]+a[i+1]>=l:
            cnt=i+1
            flag=True

if not flag:
    print("Impossible")
    exit()

ans=[cnt]

for i in range(cnt-1,0,-1):
    ans.append(i)
for i in range(cnt+1,n):
    ans.append(i)
ans=ans[::-1]
print("Possible")
for i in range(len(ans)):
    print(ans[i])
