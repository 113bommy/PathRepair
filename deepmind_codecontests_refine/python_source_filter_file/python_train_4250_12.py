a,b,k=map(int,input().split())
ct=0
for i in range(1,101):
  if a%i==0 and b%1==0:
    ct+=1
  if ct==k:
    break
print(i)