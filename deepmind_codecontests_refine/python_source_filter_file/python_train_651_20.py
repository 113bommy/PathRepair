#dt = {} for i in x: dt[i] = dt.get(i,0)+1
import sys;input = sys.stdin.readline
inp,ip = lambda :int(input()),lambda :[int(w) for w in input().split()]

for i in range(inp()):
    n = inp()
    ans = [i for i in range(2,2*n+1,2)]
    print(*ans)