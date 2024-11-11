from itertools import starmap


def cross(a, b):
    return a.real * b.imag - a.imag * b.real


q = int(input())
while q:
    q -= 1
    p0, p1, p2, p3 = starmap(complex, zip(*[map(int, input().split())] * 2))
    max_x1, min_x1 = (p0.real, p1.real) if p0.real > p1.real else (p1.real, p0.real)
    max_y1, min_y1 = (p0.imag, p1.imag) if p0.imag > p1.imag else (p1.imag, p0.imag)
    max_x2, min_x2 = (p2.real, p3.real) if p2.real > p3.real else (p2.real, p3.real)
    max_y2, min_y2 = (p2.imag, p3.imag) if p2.imag > p3.imag else (p2.imag, p3.imag)
    if any((max_x1 < min_x2, max_x2 < min_x1, max_y1 < min_y2, max_y2 < min_y1)):
        print(0)
        continue
    print(int(cross(p1 - p0, p2 - p0) * cross(p1 - p0, p3 - p0) < 1e-6 and
              cross(p3 - p2, p0 - p2) * cross(p3 - p2, p1 - p2) < 1e-6))