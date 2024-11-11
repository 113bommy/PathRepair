N,M = map(int, input().split())
a_n = list(map(int, input().split()))
g = a_n.copy()

while not any(x%2 for x in g): g = [x//2 for x in g]
if not all(x%2 for x in g): print(0); exit(0)
def gcd(a,b):
  while b: a,b = b,a%b
  return a
lcm = lambda a,b: a*b//gcd(a,b)
tot = 1
for x in l: tot = lcm(tot,x//2)
print((m//tot+1)//2)