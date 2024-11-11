a,b,c,d=list(map(int,input().split()))
import math
def yakusuu(n):
  return n//c+n//d-n//(c*d/math.gcd(c,d))

print(int(b-a+1-(yakusuu(b)-yakusuu(a-1))))
      