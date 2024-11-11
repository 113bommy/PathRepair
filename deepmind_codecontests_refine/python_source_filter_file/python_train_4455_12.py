a,b=(int(x) for x in input().split())
z=0
for i in range(b,a+2):
  z=(z+(a-i+1)*i+1)%(1e9+7)
print(z)