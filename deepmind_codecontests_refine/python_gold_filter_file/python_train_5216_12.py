from bisect import bisect_left as bl
n=int(input())
s=list(map(int,input().split()))
ans=1
x=1
for i in range(1,n):
    if s[i-1]*2>=s[i]:
        x+=1
    else:
        ans=max(ans,x)
        x=1
print(max(ans,x))
