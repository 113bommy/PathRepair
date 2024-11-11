n=int(input())
s=len(bin(n))-2
if 2**(s-1)==n:
  print("No")
elif n==3:
  print("Yes")
  for i in range(1,6):
    print(i,i+1)
else:
  print("Yes")
  print(2**(s-1)-1,1+n)
  for i in range(1,2**(s-1)-1):
    print(i,i+1)
    print(i+n,i+n+1)
  print(2**(s-1),2**(s-1)+1)
  print(2**(s-1)+1+n,1)
  print(2**(s-1),1)
  print(2**(s-1)+n,2**(s-1)+1+n)
  for i in range(2**(s-1)+2,n+1):
    print(i,i-1+n)
    print(i+n,i-2**(s-1))
    
      
