class Rect:
    def __init__(self, x1, y1, x2, y2):
        self.x1 = int(x1)
        self.y1 = int(y1)
        self.x2 = int(x2)
        self.y2 = int(y2)
        self.width = abs(self.x2 - self.x1)
        self.height = abs(self.y2 - self.y1)
        self.area = self.width * self.height

def overlap(r1, r2):
    olap_x = max(min(r1.x2, r2.x2) - max(r1.x1,r2.x1), 0)
    olap_y =  max(min(r1.y2, r2.y2) - max(r1.y1,r2.y1), 0)
    if olap_x * olap_y > 0:
        return Rect(max(r1.x1,r2.x1), max(r1.y1,r2.y1), min(r1.x2, r2.x2), min(r1.y2, r2.y2)) 
    else:
        return Rect(0, 0, 0, 0)

white = Rect(*input().split())
black1 = Rect(*input().split())
black2 = Rect(*input().split())

b1_olap = overlap(white, black1)
b2_olap = overlap(white, black2)
olap_olap = overlap(b1_olap, b2_olap)



#print(white.area, b1_olap.area, b2_olap.area, olap_olap.area, white.area - b1_olap.area - b2_olap.area + 2*olap_olap.area)

if white.area - b1_olap.area - b2_olap.area + 2*olap_olap.area > 0:
    print("YES")
else:
    print("NO")
