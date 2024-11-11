n=int(input());
A=[int(input().replace(' ',''),2)for _ in[0]*n]
p=[0]*2**n
p[0]=1
for I in range(2**n-1):
 a=A[bin(I).count('1')]&~I
 for j in range(n):
  if a&1<<j:p[I|1<<j]+=p[I];p[I|1<<j]%=10**9+7
print(p[-1])