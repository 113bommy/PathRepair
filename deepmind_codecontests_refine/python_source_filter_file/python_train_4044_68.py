n= int(input())
a,b,c = 2,1,3
for i in range(n-1):
  a,b,c=b,c,b+c
print(a)