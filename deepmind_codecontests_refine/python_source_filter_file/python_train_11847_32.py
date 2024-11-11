N,A,B=map(int,input().split())
if (A-B)%2==0:
  print((B-A)/2)
  exit()

print(min((A+B-1)//2,(N-B+N-A+1)//2))