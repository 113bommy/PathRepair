import fractions as f 
a=int(input())
ans=0
for i in range(1,a+1):
 for j in range(1,a+1):
  for k in range(1,a+1):
   b=f.gcd(i,j)
   ans+=f.gcd(b,k)
print(ans)