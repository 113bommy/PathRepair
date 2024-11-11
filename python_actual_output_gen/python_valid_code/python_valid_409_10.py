n=int(input())
l=sorted(map(int,input().split()))
ans=1
l[0]=1
for i in range(1,n):
    if l[i]>l[i-1]: l[i]=l[i-1]+1; ans=l[i]+1
print(ans)