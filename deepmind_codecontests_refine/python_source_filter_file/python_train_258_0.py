import math
import sys

def calculate_area(n, x, y, vertices):
    r_max = -sys.maxsize
    r_min = sys.maxsize

    last_d = -1
    for v in vertices:
        d = distance_two_points(v, (x, y))
        if d > r_max:
            r_max = d
        if d < r_min:
            r_min = d

    last_v = vertices[0]
    for i in range(1,n):
        d_min, i_point = distance_point_to_line(last_v, vertices[i], (x, y))
        if d_min < r_min and is_in_range(i_point, last_v, vertices[i]):
            r_min = d_min
        last_v = vertices[i]
    d_min, i_point = distance_point_to_line(last_v, vertices[0], (x, y))
    if d_min < r_min and is_in_range(i_point, last_v, vertices[i]):
        r_min = d_min

    return math.pi * (r_max**2 - r_min**2)

def distance_two_points(p1, p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def distance_point_to_line(p1, p2, p0):
    a = p2[1] - p1[1]
    b = p1[0] - p2[0]
    c = p2[0]*p1[1] - p2[1]*p1[0]
    dist = math.fabs(a*p0[0] + b*p0[1] + c) / math.sqrt(a**2 + b**2)
    x_int = (b*(b*p0[0]-a*p0[1]) - a*c)/(a**2 + b**2)
    y_int = (a*(-b*p0[0]+a*p0[1]) - b*c)/(a**2 + b**2)
    return dist, (x_int, y_int)

def is_in_range(i_point, p1, p2):
    x_min = p1[0] if p1[0] <= p2[0] else p2[0]
    x_max = p1[0] if p1[0] > p2[0] else p2[0]
    y_min = p1[1] if p1[1] <= p2[1] else p2[1]
    y_max = p1[1] if p1[1] > p2[1] else p2[1]

    return x_min <= i_point[0] <= x_max and y_min <= i_point[1] <= y_max


if __name__ == "__main__":
    n, x, y = input().split()
    n, x, y = int(n), int(x), int(y)
    vertices = [None]*n
    for i in range(n):
        x_i, y_i = input().split()
        vertices[i] = (int(x_i), int(y_i))
    area = calculate_area(n, x, y, vertices)
    print(area)