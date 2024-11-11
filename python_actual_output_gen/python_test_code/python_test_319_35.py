N,A,B = map(int,input().split())
if (A-B)%2==0:
  print((B-A)//2)
else:
  print(min((A+B)//2,(N*2-A-B)//2))