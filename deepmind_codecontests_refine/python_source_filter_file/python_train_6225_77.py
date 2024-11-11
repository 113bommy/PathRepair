import numpy as np
a,b=map(int,input().split())
print((a*b)//np.gcd(a,b))