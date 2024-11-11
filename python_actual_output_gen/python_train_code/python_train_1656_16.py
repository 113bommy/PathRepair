n=int(input())
a=[0]*(n+1)
six=0
nine=0
for i in range(1,n+1):
  if i>6**(six+1):
    six+=1
  if i>9**(nine+1):
    nine+=1
  a[i]=min(a[i-1],a[i-6**six],a[i-9**nine])+1
print(a[n])