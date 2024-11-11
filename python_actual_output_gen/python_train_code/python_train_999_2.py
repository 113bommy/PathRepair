n=int(input())
a=list(map(int,input().split()))
count=0
ans=-1
for i in range(1,len(a)):
    if a[i]==a[i-1]+a[i-2]:
        count+=1
    else:
        c=i
        ans=max(ans,count)
        count=0
ans=max(ans,count)
if n==1:
    print(1)
elif ans==0:
    print(2)
else:
    print(ans+2)