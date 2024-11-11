A=1
for i in range(1,int(input)+1):
  A*=i
  A%=1000000007
print(A)