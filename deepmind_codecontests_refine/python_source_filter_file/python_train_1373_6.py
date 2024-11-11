import sys
# sys.stdin = open("billboard.in", "r")
# sys.stdout = open("billboard.out", "w")


class Rect:
    def __init__(self, is_input=True):
        if is_input:
            self.x1, self.y1, self.x2, self.y2 = map(int, input().split())
    
    def area(self):
        return (self.x2 - self.x1) * (self.y2 - self.y1)

def findIntersection(q, p):
    area = 0
    y_intersection = max(min(q.y2, p.y2) - max(q.y1, p.y1),0)
    if y_intersection:
        x_intersection = max(min(q.x2, p.x2) - max(q.x1, p.x1),0)
        area = y_intersection * x_intersection
    return area

recs = []
for _ in range(3):
    recs.append(Rect())

i1 = findIntersection(recs[0], recs[1])
i2 = findIntersection(recs[0], recs[2])
i3 = findIntersection(recs[1], recs[2])
i = 0
if i3 > 0:
    overlap = Rect(is_input=False)
    overlap.x1 = max(recs[1].x1, recs[2].x1)
    overlap.y1 = max(recs[1].y1, recs[2].y2)
    overlap.x2 = min(recs[1].x2, recs[2].x2)
    overlap.y2 = min(recs[1].y2, recs[2].y2)
    i = findIntersection(overlap, recs[0])

if i1 + i2 - i >= recs[0].area():
    print("NO")
else:
    print("YES")

