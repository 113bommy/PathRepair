n=int(input())

a=list(map(int,input().split()))
sum=[0]*(n+2)
pre=[0]*(n+2)
for i in range(n-1,-1,-1):
    sum[i]=sum[i+2]+a[i]
    pre[n-1-i]=a[n-1-i]
    if n-1-i>0:
        pre[n-1-i]+=pre[n-i-2]

ans=0
for i in range (n):
    #removing ith choclate
    odd_sum=sum[i+1]
    even_sum=sum[i+2]
    if i-2>=0:
        odd_sum+=pre[i-2]
    if i-1>=0:
        even_sum+=pre[i-1]
    if odd_sum==even_sum:
        ans+=1
print(ans)

