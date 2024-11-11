import math
a,b,c,d=map(int,input().split())
print('Yes' if math.ceil(c/b)+1>math.ceil(a/d) else 'No')  