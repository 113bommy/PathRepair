a,b,c = map(int, input().split())
di = (b**2 - 4*a*c)**(1/2)
if a > 0:
 print((-b + di)/(2*a))
 print((-b - di)/(2*a))
else:
 print((-b - di)/(2*a))
 print((-b + di)/(2*a))
