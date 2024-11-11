import math
n, t, k, d = map(int,input().split())
o1 = math.ceil(n/k)*t
i = 1
while(i*t < d):
    i += 1
n -= i*k
o2 = math.ceil((n/2)/k)*t + d
 
print('YES' if o2 < o1  and n >= 0 else 'NO')