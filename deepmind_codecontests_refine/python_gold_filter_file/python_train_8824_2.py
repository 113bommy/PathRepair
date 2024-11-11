a,n=0,int(input())+1
for i in range(1,n):
  for j in range(i,n,i): a+=j
print(a)