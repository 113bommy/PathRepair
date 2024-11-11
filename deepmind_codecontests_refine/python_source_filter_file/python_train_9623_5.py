n=int(input())
p=list(map(int,input().split()))
cx=[i for i in range(n+1)]
for i in range(2,n+1):
  cx[i]=cx[i-1]^cx[i]
x=p[0]
for i in range(1,n):
  x^=p[i]
for i in range(1,n+1):
  m=n%i
  rep=n//i
  if rep%2==0:
    x^=cx[m]
  else:
    x^=cx[i]^cx[m]
print(x)