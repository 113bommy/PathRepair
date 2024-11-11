l=int(input())
a=int(input())
b=int(input())
c=int(input())
d=int(input())
if a%c==0 and b%d==0:
  if a/c>=b/d:
    print(l-(a//c))
  else:
    print(l-(b//d))
else:
  x=(a//c)+1
  y=(b//d)+1
  if x>=y:
    print(l-x)
  else:
    print(l-y)
