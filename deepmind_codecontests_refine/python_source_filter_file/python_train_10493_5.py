import math

a, b, x=map(int, input().split())
ans=math.degrees(math.atan(2*(a*a*b-x)/a**3) if x>=a**2*b/2 else math.atan(a**2*b/(2*x)))
print(ans)