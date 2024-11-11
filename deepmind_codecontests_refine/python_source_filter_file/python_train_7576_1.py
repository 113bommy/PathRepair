n=int(input())
import fractions
a = list(map(int, input().split()))
lcm = a[0]
for i in a[1:]:
  lcm = lcm * i // fractions.gcd(lcm, i)
b=[]
for i in a:
  b.append(lcm//i)
ans=sum(b)%(10**9+7)
print(ans)