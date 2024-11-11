N=int(input())
n=N-1
for i in range(1,int(N**(1/2))):
    if N%i==0:
      n=min(n,i+N/i-2)
print(int(n))