s=input()
n=0
ans=0
A=[0]*2019
A[0]=1
for i,j in enumerate(reversed(s)):
  n=(n+int(j)*pow(10,i,2019))%2019
  print(i,n)
  A[n]+=1
for i in A:
  ans+=i*(i-1)//2
print(ans)