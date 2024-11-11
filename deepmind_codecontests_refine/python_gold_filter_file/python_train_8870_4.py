import math
n,a, b, k =  tuple(map(int,input().split()))
monstors = list(map(int,input().split()))
techs = []

diff = math.ceil(b/a)
for monstor in monstors:
    if monstor%(a+b) == 0:
        techs.append(diff)
    else:
        monstor = monstor%(a+b) - a
        if monstor <= 0:
            techs.append(0)
        else:
            techs.append( math.ceil(monstor/a) )
points = 0
for tech in sorted(techs):
    if tech <= k:
        points+=1
        k-=tech
print(points)