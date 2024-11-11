n=int(input())
x=10**12
i=1
c=0
while x>i:
  x=(n-i)//i
  if (n-i)%i==0 and n-i!=i:c+=x
  i+=1
print(c)
    
  