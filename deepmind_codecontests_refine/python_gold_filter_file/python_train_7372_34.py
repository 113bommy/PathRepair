d,g = map(int,input().split())
"""
PC = []
for i in range(d):
    pc = list(map(int,input().split()))
    PC.append(pc)
"""
PC =[list(map(int,input().split())) for i in range(d)]

def solve(g,i):
    if i<=0:
        return float('inf')
    n = min(int(g/(100*i)),PC[i-1][0])
    score = 100 * i * n
    if n == PC[i-1][0]:
        score += PC[i-1][1]
    if g > score:
        n += solve(g-score,i-1)
    return min(n,solve(g,i-1))

print(solve(g,d))