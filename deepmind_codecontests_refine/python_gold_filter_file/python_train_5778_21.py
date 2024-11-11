import math
def sqr(x):
    return x * x


def side_(a,b):
    cos_120 = -0.5
    return abs(((sqr(a) + sqr(b)) - (2 * a * b * cos_120)) ** 0.5)

def triangle_area(a,b,c):
    p = (a + b + c) / 2
    return abs((p * (p-a) * (p-b) * (p-c)) ** 0.5)



a1,a2,a3,a4,a5,a6 = map(int,input().split())
sin_120 = (-1) * ((3 ** 0.5) / 2)
area1 = abs((a1 * a2) / 2 * sin_120)
area2 = abs((a3 * a4) / 2 * sin_120)
area3 = abs((a5 * a6) / 2 * sin_120)
side1 = side_(a1,a2)
side2 = side_(a3,a4)
side3 = side_(a5,a6)
s = triangle_area(side1,side2,side3)
all_area = area1 + area2 + area3 + s
print(round(all_area / ((3 ** 0.5) / 4)))