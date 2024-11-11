N,M=map(int,input().split())
g=1
for i in range(1,int(M**(1/2))+1):
  if M%i==0:
    if i>=N:
      g=M/i
      print(g)
      exit()
    elif i<=M/N:
      g=i
print(int(g))