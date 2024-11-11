n,m = map(int,input().split())
gcd = m//n
while n*gcd != m:
  gcd = M//n
  n = 1 + (M-1)//gcd
print(gcd)