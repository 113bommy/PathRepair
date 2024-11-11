x,k,d=map(int, input().split())
x=abs(x)
a=x%d
b=(x-a)//d
if b <= k:
  if (b ^ k) & 1:
    print(-x%d)
  else:
    print(x%d)
else:
  print(x-k*d)
