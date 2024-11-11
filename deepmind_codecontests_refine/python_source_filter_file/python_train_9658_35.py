
c=0
n = int(input())
a= [int(i) for i in input().split()]
for i in range(0,n+1,2):
  if a[i]%2==1:
    c+=1

print(c)



