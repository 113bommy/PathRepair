T=input()
n=len(T)
i=r=a=0
for c in T:
  k=i-r
  if c=='0':
    r+=k&1
  else:
    a+=i//2-k//2+(k&1)*(n-i)
  i+=1
print(a)
