s  = input()
y = s.count("y")
x = s.count("x")
t = abs(y-x)
if y > x:
   print("y"*y)
else:
   print("x"*x)
