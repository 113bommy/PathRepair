import fractions
n=int(input())
t=[int(input()) for i in range(n)]
gc=t[0]
for i in range(n):
  gc=(gc*t[i]) / fractions.gcd(gc,t[i])
print(int(gc))