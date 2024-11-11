n=int(input())
x=0
for i in range(1,n+1):
  for j in range(i,n+1,i):
    x+=j
print(x)