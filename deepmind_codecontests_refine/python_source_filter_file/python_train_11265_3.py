



n = int(input())
t  = list(map(int,input().split()))




pre = [1]*n
back=[1]*n


for i in range(1,n):
    if t[i]>t[i-1]:
        pre[i]=pre[i-1]+1

for i in range(n-2,-1,-1):
    if t[i]<t[i+1]:
        t[i]=t[i+1]+1



ans=0

for i in range(n):

    ans = max(ans , pre[i], back[i])

    if i==0:
        ans = max(ans , back[i])
    elif i==n-1:
        ans=  max(ans , pre[i])
    else:
        if t[i+1]>t[i-1]:
            ans = max(ans , pre[i-1]+back[i+1])

print(ans)
