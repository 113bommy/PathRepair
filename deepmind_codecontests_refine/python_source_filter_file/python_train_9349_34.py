K,A,B = map(int,input().split())
if A+2>=B or K-1<A:
  print(1+K)
else:
  print(B*((K-(A-1))//2)+(K-(A-1))%2)
