n,a,b=map(int,input().split())
total=0
for i in range(n+1):
  j=eval("+".join(str(i)))
  if a<=int(j)<=b:
    total+=int(i)
print(total)
