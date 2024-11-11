n, k = map(int,input().split())
for i in range(1,n):
  a=max(0,i-k)*(n//b)+max(0,n%i-k+1)
if k==0:
  a-=n
print(a)