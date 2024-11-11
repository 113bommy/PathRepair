N,A,B = list(map(int,input().split()))
if (A+B) %2 == 0:
  print(abs(B-A)//2)
else:
  print(min((A+B+1)//2,(N-A+1+N-B)//2))
  