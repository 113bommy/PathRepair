import sys

sys.setrecursionlimit(10 ** 5)
int1 = lambda x: int(x) - 1
p2D = lambda x: print(*x, sep="\n")
def II(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def LLI(rows_number): return [LI() for _ in range(rows_number)]
def SI(): return sys.stdin.readline()[:-1]

for _ in range(II()):
    n=II()
    aa=[0]+LI()
    ans=0
    for i in range(n):
        if i==aa[i] and i+1!=aa[i+1]:ans+=1
    print(ans)
