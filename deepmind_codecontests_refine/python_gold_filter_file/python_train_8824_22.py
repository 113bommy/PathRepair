n=int(input())
a=0
for i in range(1,n+1):
  for j in range(i,n+1,i):a+=j
print(a)