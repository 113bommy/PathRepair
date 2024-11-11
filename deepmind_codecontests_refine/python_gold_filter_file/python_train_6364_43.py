import sys
stdin = sys.stdin
 
sys.setrecursionlimit(10**5) 
 
def li(): return map(int, stdin.readline().split())
def li_(): return map(lambda x: int(x)-1, stdin.readline().split())
def lf(): return map(float, stdin.readline().split())
def ls(): return stdin.readline().split()
def ns(): return stdin.readline().rstrip()
def lc(): return list(ns())
def ni(): return int(stdin.readline())
def nf(): return float(stdin.readline())

n = ni()
a = list(li())
anst = 0
anscost = float('inf')
for t in range(1,1001):
    cost = 0
    for ai in a:
        if ai < t-1:
            cost += ((t-1) - ai)
        elif ai > t+1:
            cost += (ai - (t+1))
            
    if cost < anscost:
        anscost = cost
        anst = t
        
print(anst, anscost)