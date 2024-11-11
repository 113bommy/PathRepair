n,k=map(int,input().split())
for _ in range(k):
       if(n%10==0):n=n/10
       if(n%10!=0):n=n-1
print(int(n))