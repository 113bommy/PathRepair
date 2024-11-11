t1,t2 = map(int,input().split())
a1,a2 = map(int,input().split())
b1,b2 = map(int,input().split())
import math
f = (a1-b1)*t1
s = (a2-b2)*t2
if f == -s:
  print("infinity")
elif (f>0 and s>0) or (f<0 and s<0):
  print(0)
elif f//(-(f+s)) == math.ceil(f/(-(f+s))):
  print(f//(-(f+s))*2)
else:
  print(f//(-(f+s))*2+1)