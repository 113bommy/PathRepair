n,k=map(int,input().split())
k=240-k
sum=5
i=1
while (sum<k)&(i<=n):
    sum+=(i+1)*5
    i+=1
print(i-1)