n,k=map(int,input().split())
k=240-k
sum=0
i=1
while (sum+i*5<=k)&(i<=n):
    sum+=(i)*5
    i+=1
print(i-1)