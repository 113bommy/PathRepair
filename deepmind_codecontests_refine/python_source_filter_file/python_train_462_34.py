import math
r,x,y,x1,y1 = [int(x) for x in input().split()]
d = math.sqrt(((x1-x)*(x1-x)) + ((y1-y)*(y1-y)))
dic = int(d//(2*r))
print(dic)