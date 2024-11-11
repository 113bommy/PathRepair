def get_problem():
    from sys import stdin
    inp = list(map(lambda s: s.strip(), stdin.readlines()))
    k, n, m = map(int, inp[0].split())
    plate = []
    for _k in range(k):
        layer = []
        for _n in range(n):
            layer.append(inp[2 + _k*(n+1) + _n])
        plate.append(layer)

    def valid(pt):
        x, y, z = pt
        if z < 0 or z >= k:
            return False
        if y < 0 or y >= n:
            return False
        if x < 0 or x >= m:
            return False
        return plate[z][y][x] == '.'

    delta = [ (-1, 0, 0), (1, 0, 0), (0, -1, 0), (0, 1, 0), (0, 0, -1), (0, 0, 1) ]
    def neighbors(pt):
        x, y, z = pt
        possible_neighbors = [ (x + dx, y + dy, z + dz) for dx, dy, dz in delta ]
        return list(filter(valid, possible_neighbors))

    x, y = map(int, inp[2 + k*(n+1)].split())
    start = (x - 1, y - 1, 0)
    return start, neighbors

def solve(start, neighbors):
    visited = [ start ]
    to_visit = neighbors(start)
    ans = 1
    while len(to_visit) > 0:
        node = to_visit.pop(0)
        if node not in visited:
            ans += 1
            visited.append(node)
            to_visit.extend(neighbors(node))
    return ans

print(solve(*get_problem()))
