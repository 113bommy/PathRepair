def gcd(a,b):
  if b==0:
    return a
  else:
    return gcd(b,a%b)

n=int(input())
for _ in range(n):
  a,b,c,d=map(int,input().split())
  if a%b>c or b>d:
    print('No')
  else:
    if b==d:
      print('Yes')
    elif a%b+d==a:
      print('Yes')
    else:
      if c+gcd(b,d)>=b:
        print('Yes')
      else:
        print('No')