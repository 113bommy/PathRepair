for i in range(int(input())):
  n=int(input())
  if n==1:
    print(0)
  else:
    ans=0
    for i in range(1,n//2+1):
      ans+=i*((2*i+1)**2-(2*i-1)**2)
    print(ans)
