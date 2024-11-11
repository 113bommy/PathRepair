n,a,b=map(int,input().split())
total=0
for i in range(n+1):
  i=eval("+".join(str(i)))
  if a<=int(i)<=b:
    total=int(i)
print(total)