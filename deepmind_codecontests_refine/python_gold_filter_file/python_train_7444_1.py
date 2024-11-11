def get_bounds(points):
    if len(points) == 1:
        return points[:]
    points.sort()
    bounds = [points[0], points[1]]
    for xi, yi in points[2:]:
        while len(bounds) > 1 and not is_convex(bounds, xi, yi):
            del bounds[-1]
        bounds.append((xi, yi))
    return bounds


def is_convex(bounds, x2, y2):
    x1, y1 = bounds[-1]
    x0, y0 = bounds[-2]
    return (x1 - x0) * (y2 - y1) < (y1 - y0) * (x2 - x1)



def read_data():
    n, p, q = map(int, input().split())
    ABs = []
    for i in range(n):
        a, b = map(int, input().split())
        ABs.append((a, b))
    return n, p, q, ABs

def solve(n, p, q, ABs):
    '''
    min sum(ds)
    s.t. sum(ds[i] * As[i]) >= p and sum(ds[i] * Bs[i]) >= q
    '''
    bounds = get_bounds(ABs)
    a0, b0 = bounds[0]
    if len(bounds) == 1:
        return max(p/a0, q/b0)
    record = float('Inf')
    for a1, b1 in bounds[1:]:
        steps = min(max(p/a0, q/b0), max(p/a1, q/b1))
        den = a0 * b1 - b0 * a1
        if den != 0:
            r0 = (b1 * p - a1 * q)/den
            r1 = - (b0 * p - a0 * q)/den
            if r0 > 0 and r1 > 0:
                steps = min(steps, r0 + r1)
        a0 = a1
        b0 = b1
        record = min(record, steps)
    return record

n, p, q, ABs = read_data()
print(solve(n, p, q, ABs))