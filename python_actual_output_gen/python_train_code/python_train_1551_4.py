mod=100000007
n,k=list(map(int,input().split(" ")))
sum=0
for i in range(k,n+2):
  sum=sum+i*(n-i+1)+1
print(sum%mod)
  