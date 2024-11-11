R = lambda : map(int, input().split())
px,py = [],[]
for _ in range(3):
    x,y=R()
    px.append((x,y))
    py.append((y,x))
px=sorted(px)
py=sorted(py)

def solve(p):
    if p[0][0]==p[2][0]:
        return 1
    if p[0][0]==p[1][0] and (p[2][1]<=p[0][1] or p[2][1]>=p[1][1]):
        return 2
    if p[1][0]==px[2][0] and (p[0][1]<=p[1][1] or p[0][1]>=p[2][1]):
        return 2
    return 3
        
print(min(solve(px),solve(py)))