n,a=int(input()),list(map(int,input().split()))
x,s=[0]*(n+1),0
for i in range(1,n+1):
  x[i]=i^x[i-1]
  if (n//i)%2:s^=x[i-1]
  s^=x[n%i]
  s^=a[i-1]
print(s)