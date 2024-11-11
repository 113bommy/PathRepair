R=lambda:list(map(int,input().split()))
n,k=R()
a=k
for i in R():
  if k%i==0:
    a=min(a,k//i)
print(a)
