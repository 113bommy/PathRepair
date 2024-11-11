from sys import stdin
import math
inp = lambda : stdin.readline().strip()

t = int(inp())
for _ in range(t):
    n = int(inp())*2
    o = 360/n * (math.pi/180)
    ans = 2*(1/(2*math.sin(o/2)))
    print(ans)