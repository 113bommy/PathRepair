import math
n = int(input())
print("1" if(n<=2) else  int((n/3)*2+math.ceil(float(n%3)/2)))