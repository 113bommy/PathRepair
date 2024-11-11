n=int(input())

ans=0
for i in rabge(1,n+1):
  num=n//i
  ans+=i*num*(num+1)/2
  
print(ans)