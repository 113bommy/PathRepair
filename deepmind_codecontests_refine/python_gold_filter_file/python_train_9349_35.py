K,A,B = map(int,input().split())
if A+2>=B or K-1<A:
  print(1+K)
else:
  print((B-A)*((K-(A-1))//2)+A+(K-(A-1))%2)