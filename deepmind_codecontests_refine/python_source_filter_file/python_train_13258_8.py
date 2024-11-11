

def inpNum(): return int(input())
def inpNums(): return map(int,input().split())
def inpList(): return list(map(int,input().split()))
def inpMatrix(rows): return [list(map(int, input().split())) for _ in range(rows)]



s,n = inpNums()
for xi,yi in sorted(inpMatrix(n)):
    if s<xi:
        s = -1
        break
    else:
        s = s+yi
if s<0: print("NO")
else: print("YES")

