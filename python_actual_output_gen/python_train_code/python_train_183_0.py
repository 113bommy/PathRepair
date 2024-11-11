a,b,c,x,y=map(int,input().split())

if x>y:
  print(min(2*x*c,2*y*c+(x-y)*a,a*x+b*y))
else:
  print(min(2*y*c,2*x*c+(y-x)*a,a*x+b*y))