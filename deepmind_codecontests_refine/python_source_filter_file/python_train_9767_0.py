a,b,k=map(int,input().split())
for i in range(k):
  if k%2:
    a,b=a+b//2,b//2
  else:
    a,b=a//2,a//2+b
print(a,b)