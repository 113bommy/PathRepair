n=int(input())
f=lambda x:sum(map(int,str(x)))
v=1e9
for i in range(1,n//2+3):
  a=i
  b=n-i
  v=min(v,f(a)+f(b))
print(v)