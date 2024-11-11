N,M=input().split()
N=int(N)
M=int(M)
if M%2==0:
  print((N/M)**3+((N+M/2)/M)**3)
else:
  print((N/M)**3)