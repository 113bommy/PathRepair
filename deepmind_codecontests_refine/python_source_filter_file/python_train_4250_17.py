a,b,k=map(int,input().split())
v=[]

for i in range(1,101):
  if a%i==0 and b%i==0:
    v.append(i)
    
print(v[k-1])