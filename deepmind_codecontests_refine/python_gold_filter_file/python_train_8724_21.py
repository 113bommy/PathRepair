n,m=map(int,input().split())
a=[]
for _ in range(n):
  _,*b=map(int,input().split())
  a+=b
print(sum(n==a.count(i+1)for i in range(m)))