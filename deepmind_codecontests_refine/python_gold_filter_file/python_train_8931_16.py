n,k=map(int,input().split())
p=0
for i in range(1,n+1):
  if i<k: p+=4*0.5**len(bin(~-k//i))
  else: p+=1
print(p/n)