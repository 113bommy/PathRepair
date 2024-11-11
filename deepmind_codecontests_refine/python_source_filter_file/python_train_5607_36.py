x, y = map(int, input().split())

if x < y:
   print(min(abs(abs(x)-abs(y))+1, y-x))
elif x*y >= 0:
   print(abs(abs(x)-abs(y))+2)
else:
   print(abs(abs(x)-abs(y)+1))