n = int(input())
for i in range(4,n+1):
  if((n-i)%2==0):
    n=n-i
    print(n,i)
    break
  elif((n-i)%3==0):
    n=n-i
    print(n,i)
    break
