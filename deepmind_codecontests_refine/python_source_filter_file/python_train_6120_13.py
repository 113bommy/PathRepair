import math
import itertools


def intersections(T, x1, y1, c1, x2, y2, c2):
    # 2つの円 (x - x_i)**2 + (y - y_i)**2 = (T/c_i)**2 の交点を求める
    left = ((c1 * c2)**2) * ((x1 - x2)**2 + (y1 - y2)**2)
    right = (T**2) * ((c1 + c2)**2)
    # 交点なし
    if left > right:
        return list()
    # 交点1つ
    if left == right:
        return [((c1*x1 + c2*x2) / (c1 + c2), (c1*y1 + c2*y2) / (c1 + c2))]
    # 交点2つ
    r1, r2 = T / c1, T / c2
    p12 = (x2 - x1, y2 - y1)
    coef = (r1**2 + p12[0]**2 + p12[1]**2 - r2**2) / (2 * (p12[0]**2 + p12[1]**2))
    p1h = (coef * p12[0], coef * p12[1])
    coef = (r1**2 - p1h[0]**2 - p1h[1]**2) / (p12[0]**2 + p12[1]**2)
    coef = math.sqrt(max(0, coef))  # 誤差を吸収
    hq1 = (- coef * p12[1], coef * p12[0])
    hq2 = (coef * p12[1], - coef * p12[0])
    return [
        (x1 + p1h[0] + hq1[0], y1 + p1h[1] + hq1[1]),
        (x1 + p1h[0] + hq2[0], y1 + p1h[1] + hq2[1])
    ]


def check(T, K, points):
    N = len(points)
    target_points = [(p[0], p[1]) for p in points]
    for pair in itertools.combinations(range(N), 2):
        p1 = points[pair[0]]
        p2 = points[pair[1]]
        target_points += intersections(T, p1[0], p1[1], p1[2], p2[0], p2[1], p2[2])
    for tp in target_points:
        cnt = 0
        for p in points:
            d2 = (tp[0] - p[0])**2 + (tp[1] - p[1])**2
            if d2 <= (T/p[2])**2 + 10**(-10):  # 誤差を吸収
                cnt += 1
            if cnt >= K:
                return True
    return False


def main():
    eps = 10 ** (-8)
    N, K = list(map(int, input().split()))
    points = [list(map(int, input().split())) for _ in range(N)]
    ng, ok = 0, 3 * (10**5)  # Time
    while ok - ng > eps:
        mid = (ok + ng) / 2
        if check(mid, K, points):
            ok = mid
        else:
            ng = mid
    print(ok)


if __name__ == '__main__':
    main()