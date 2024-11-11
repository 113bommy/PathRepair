n,k=list(map(int,input().split()))
r=0
r+=(n//k)**3
if k%2==0:
  r+=((n-k//2)//k)**3
print(r)