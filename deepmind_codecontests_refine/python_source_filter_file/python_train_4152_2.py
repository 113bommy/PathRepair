def cross(x, y):
    return (x.conjugate() * y).imag
 
def area_polygon(points):
    area = 0
    n = len(points)
    for i in range(n):
        area += cross(points[i], points[(i+1)%n])
    return area / 2
     
     
import sys
 
p = []
for line in sys.stdin:
    x, y = map(float, line.split(','))
    p.append(x+y*1j))
 
print(abs(area_polygon(p)))