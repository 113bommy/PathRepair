import math
x,y=map(int,input().split())
if(math.log(x)*y>math.log(y)*x):
    print(">")
if(math.log(x)*y<math.log(y)*x):
    print("<")
else:
    print("=")