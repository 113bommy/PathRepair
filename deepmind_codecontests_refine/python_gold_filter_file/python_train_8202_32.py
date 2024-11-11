n=int(input())
c=0
for i in range(1,int(n**.5)+1):
  if n%i==0:
    if n//i-i>1:
      c+=n//i-1
print(c)