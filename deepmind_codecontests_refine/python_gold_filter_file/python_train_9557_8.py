n=int(input())
if n<=2 or n==4:
  print("No")
elif n==3:
  print("Yes")
  for i in range(5):
    print(i+1,i+2)
elif n%2==0:
  nn=n.bit_length()
  if n==2**(nn-1):
    print("No")
  else:
    print("Yes")
    print(1,2)
    print(2,3)
    print(3,n+1)
    print(n+1,n+2)
    print(n+2,n+3)
    for i in range(4,n):
      print(n+1,i)
      if i%2==0:
        print(i,i+n+1)
      else:
        print(i,i+n-1)
    n1,n2=2**(nn-1),(n+1)-2**(nn-1)
    print(n1,n)
    print(n2,2*n)
else:
  print("Yes")
  print(1,2)
  print(2,3)
  print(3,n+1)
  print(n+1,n+2)
  print(n+2,n+3)
  for i in range(4,n+1):
    print(1,i)
    if i%2==0:
      print(i,i+n+1)
    else:
      print(i,i+n-1)