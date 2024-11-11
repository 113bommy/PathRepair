a,s=map(int,input().split())
A=0
for i in range(a,b+1):
  if str(i)==str(i)[::-1]:A+=1
print(A)