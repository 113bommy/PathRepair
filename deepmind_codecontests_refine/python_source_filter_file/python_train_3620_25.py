def generate_test_case():
    import random
    random.seed(0)
    ret = list()
    n = 10
    for _ in range(5):
        plane_list = list()
        for _ in range(n):
            x, y = random.choices(range(200001), k=2)
            u = random.choice(['U', 'R', 'D', 'L'])
            plane_list.append((x, y, u))
        ret.append({
            'n': n,
            'plane_list': plane_list
        })
    return ret


def solve_simply(N, plane_list):
    # 1単位時間（5秒）ごとに衝突判定：O(N * max(X_1, Y_1, ..., X_N, Y_N))
    from collections import defaultdict
    occur_collision = False
    LIMIT_T = 200000 * 2
    t = 1
    while t <= LIMIT_T:
        location = defaultdict(int)
        same_location = False
        for plane in plane_list:
            x, y, u = plane
            x *= 2  # 移動単位が0.5なので2倍して格子点上に並べる
            y *= 2
            if u == 'U':
                y += t  # 座標はxy方向に2倍されているので速度は単位時間あたり1。
            elif u == 'R':
                x += t
            elif u == 'D':
                y -= t
            else:
                x -= t
            if location[(x, y)] > 0:
                same_location = True
                break
            location[(x, y)] += 1
        if same_location:
            occur_collision = True
            break
        t += 1
    if occur_collision:
        return t * 5
    else:
        return 'SAFE'


def get_min_t_on_same_line(N, plane_list, t_inf=2*(10**6)):
    import bisect
    from collections import defaultdict
    uy, dy = defaultdict(list), defaultdict(list)
    plane_list.sort(key=lambda p: (p[0], p[1]))  # sort by (x, y)
    for plane in plane_list:
        x, y, u = plane
        if u == 'U':
            uy[x].append(y)
        elif u == 'D':
            dy[x].append(y)
    lx, rx = defaultdict(list), defaultdict(list)
    plane_list.sort(key=lambda p: (p[1], p[0]))  # sort by (y, x)
    for plane in plane_list:
        x, y, u = plane
        if u == 'R':
            rx[y].append(x)
        elif u == 'L':
            lx[y].append(x)
    min_t = t_inf
    for y in rx.keys():  # 右向きの飛行機の対になる左向き飛行機の探索
        for x in rx[y]:
            index = bisect.bisect_right(lx[y], x)
            if index >= len(lx[y]):
                continue
            dist = lx[y][index] - x
            min_t = min(min_t, 5 * dist)
    for x in uy.keys():  # 上向きの飛行機の対になる下向き飛行機の探索
        for y in uy[x]:
            index = bisect.bisect_right(dy[x], y)
            if index >= len(dy[x]):
                continue
            dist = dy[x][index] - y
            min_t = min(min_t, 5 * dist)
    return min_t


def get_min_t_at_crossing(N, plane_list, t_inf=2*(10**6)):
    from collections import defaultdict
    import bisect
    plane_list.sort(key=lambda p: p[0])  # sort by x
    min_t = t_inf
    # (1) RU / LDの衝突：点をy+x=kのkで分類
    rx, ux = defaultdict(list), defaultdict(list)
    lx, dx = defaultdict(list), defaultdict(list)
    for plane in plane_list:
        x, y, u = plane
        k = y + x
        if u == 'U':
            ux[k].append(x)
        elif u == 'R':
            rx[k].append(x)
        elif u == 'D':
            dx[k].append(x)
        else:
            lx[k].append(x)
    for k in rx.keys():  # 右向きの飛行機の対になる上向き飛行機の探索
        for x in rx[k]:
            index = bisect.bisect_right(ux[k], x)
            if index >= len(ux[k]):
                continue
            x_diff = ux[k][index] - x
            min_t = min(min_t, 10 * x_diff)
    for k in dx.keys():  # 下向きの飛行機の対になる左向き飛行機の探索
        for x in dx[k]:
            index = bisect.bisect_right(lx[k], x)
            if index >= len(lx[k]):
                continue
            x_diff = lx[k][index] - x
            min_t = min(min_t, 10 * x_diff)
    # (2) RD / LUの衝突：点をy-x=kのkで分類
    rx, ux = defaultdict(list), defaultdict(list)
    lx, dx = defaultdict(list), defaultdict(list)
    for plane in plane_list:
        x, y, u = plane
        k = y - x
        if u == 'U':
            ux[k].append(x)
        elif u == 'R':
            rx[k].append(x)
        elif u == 'D':
            dx[k].append(x)
        else:
            lx[k].append(x)
    for k in rx.keys():  # 右向きの飛行機の対になる下向き飛行機の探索
        for x in rx[k]:
            index = bisect.bisect_right(dx[k], x)
            if index >= len(dx[k]):
                continue
            x_diff = dx[k][index] - x
            min_t = min(min_t, 10 * x_diff)
    for k in ux.keys():  # 上向きの飛行機の対になる左向き飛行機の探索
        for x in ux[k]:
            index = bisect.bisect_right(lx[k], x)
            if index >= len(lx[k]):
                continue
            x_diff = lx[k][index] - x
            min_t = min(min_t, 10 * x_diff)
    return min_t


def solve(N, plane_list):
    T_INF = 2 * (10 ** 6)
    # 同一直線上での衝突の探索
    min_t = get_min_t_on_same_line(N, plane_list, T_INF)
    # クロス衝突の探索
    min_t = min(min_t, get_min_t_at_crossing(N, plane_list, T_INF))
    if min_t == T_INF:
        return 'SAFE'
    return min_t


def main():
    N = int(input())
    plane_list = list()
    for _ in range(N):
        X, Y, U = input().split()
        X, Y = int(X), int(Y)
        plane_list.append((X, Y, U))
    print(solve(N, plane_list))


def check():
    for i, test_case in enumerate(generate_test_case()):
        print('Check {}-th test case'.format(i))
        N, plane_list = test_case['n'], test_case['plane_list']
        assert solve_simply(N, plane_list) == solve(N, plane_list)
    print('OK')


if __name__ == '__main__':
    main()
    # check()