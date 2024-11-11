n,x1,y1,x2,y2 = map(int,input().split())
flowers = []
for _ in range(n):
    fx,fy = map(int,input().split())
    flowers.append((fx,fy))
def distance(x1,y1,x2,y2):
    return ((x1-x2)**2 + (y1-y2)**2)**0.5
s1 = [distance(fx,fy,x1,y1) for fx,fy in flowers]
s2 = [distance(fx,fy,x2,y2) for fx,fy in flowers]

min_area = (max(s2)**2)

for i in range(n):
    r1 = s1[i]
    r2 = 0
    for j in range(n):
        if s1[j] > r1 and s2[j] > r2:
            r2 = s2[j]
    min_area = min(min_area, (r1**2 + r2**2))
print(min_area)
