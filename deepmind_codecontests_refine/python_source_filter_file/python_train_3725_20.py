A,B,H,M = map(int,input().split())
import math
ans = math.sqrt(A**2+B**2-2*A*B*math.cos(math.radians(30*H+0.5*M-60*M)))
print(ans)
