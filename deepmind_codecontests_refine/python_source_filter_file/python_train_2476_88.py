a,b,c,d = map(int,input().split())
import math
print("yes" if math.ceil(a/d) >= math.ceil(c/b) else "no")