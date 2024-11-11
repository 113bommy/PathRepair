n=int(input())
c=0
for i in range(n):
  if len(str(i+1))%2!=0:
    c+=1
print(c)
