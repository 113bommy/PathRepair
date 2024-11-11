N,M=input().split()
N=int(N)
M=int(M)
if M%2==0:
  print(int(N/M)**3+int((N+M/2)/M)**3)
else:
  print(int(N/M)**3)