import math
for q in range(int(input())):
    n=int(input())
    ans = 1/math.sin(math.radians(180/(4*n)))
    print(ans)