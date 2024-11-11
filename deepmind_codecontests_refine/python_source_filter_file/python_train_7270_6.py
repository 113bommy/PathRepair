import fractions
 
def lcm(a,b):
  return (a*b)//fractions.gcd(a,b)
 
N=int(input())
T=1
for i in range(T):
  T=lcm(T,int(input()))
print(T)