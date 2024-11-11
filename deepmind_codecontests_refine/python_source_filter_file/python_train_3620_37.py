import bisect
def main():
    N = int(input())
    dx = {}
    dy = {}
    dxpy = {}
    dxmy = {}
    for _ in range(N):
        x, y, u = input().split()
        x = int(x)
        y = int(y)
        if u in dx:
            if x in dx[u]:
                dx[u][x].append(y)
            else:
                dx[u][x] = [y]
            if y in dy[u]:
                dy[u][y].append(x)
            else:
                dy[u][y] = [x]
            if x + y in dxpy[u]:
                dxpy[u][x+y].append(y)
            else:
                dxpy[u][x+y] = [y]
            if x - y in dxmy[u]:
                dxmy[u][x-y].append(y)
            else:
                dxmy[u][x-y] = [y]
        else:
            dx[u] = {}
            dx[u][x] = [y]
            dy[u] = {}
            dy[u][y] = [x]
            dxpy[u] = {}
            dxpy[u][x+y] = [y]
            dxmy[u] = {}
            dxmy[u][x-y] = [y]
    for d in [dx, dy, dxpy, dxmy]:
        for j in d:
            for k in d[j]:
                d[j][k].sort()
    M = 3 * (10**5)
    ###SHOUMEN SHOTOTSU
    # U and D
    if "U" in dx and "D" in dx:
        for x in dx["U"]:
            if x not in dx["D"]:
                continue
            for y in dx["U"][x]:
                yi = bisect.bisect_left(dx["D"][x], y)
                if yi < len(dx["D"][x]):
                    M = min((dx["D"][x][yi] - y)*5, M)
    # L and R
    if "L" in dy and "R" in dy:
        for y in dy["R"]:
            if y not in dy["L"]:
                continue
            for x in dy["R"][y]:
                xi = bisect.bisect_left(dy["L"][y], x)
                if xi < len(dy["L"][y]):
                    M = min((dy["L"][y][xi] - x)*5, M)
    ###KOUSA
    # D and R
    if "D" in dy and "R" in dy:
        for s in dxmy["R"]:
            if s not in dxmy["D"]:
                continue
            for p in dxmy["R"][s]:
                yi = bisect.bisect_left(dxmy["D"][s], p)
                if yi < len(dxmy["D"][s]):
                    M = min((dxmy["D"][s][yi] - p)*10, M)
    # L and U
    if "L" in dy and "U" in dy:
        for s in dxmy["U"]:
            if s not in dxmy["L"]:
                continue
            for p in dxmy["U"][s]:
                yi = bisect.bisect_left(dxmy["L"][s], p)
                if yi < len(dxmy["L"][s]):
                    M = min((dxmy["L"][s][yi] - p)*10, M)
    # U and R
    if "U" in dy and "R" in dy:
        for s in dxpy["U"]:
            if s not in dxpy["R"]:
                continue
            for p in dxpy["U"][s]:
                yi = bisect.bisect_left(dxpy["R"][s], p)
                if yi < len(dxpy["R"][s]):
                    M = min((dxpy["R"][s][yi] - p)*10, M)
    # L and D
    if "D" in dy and "L" in dy:
        for s in dxpy["L"]:
            if s not in dxpy["D"]:
                continue
            for p in dxpy["L"][s]:
                yi = bisect.bisect_left(dxpy["D"][s], p)
                if yi < len(dxpy["D"][s]):
                    M = min((dxpy["D"][s][yi] - p)*10, M)
    return M
x = main()
if x < 3 * (10**5):
    print(x)
else:
    print('SAFE')
