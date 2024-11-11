import math
r,g,b = map(int,input().split(" "))
t = 30
r = math.ceil(r/2)
g = math.ceil(g/2)
b = math.ceil(b/2)
max = r
if(b>=r and b>=g):
    max = b
    t = t + 2
if(g>=r and g>=b):
    max = g
    t = t + 1
print(t + (max-1)*3)