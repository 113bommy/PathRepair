for _ in range(int(input())):
  n=int(input())
  j=1
  i=1
  while True:
    j=j+pow(2,i)
    if n%j==0:
      print(int(n/j))
      break
    else:
      i+=1
      
