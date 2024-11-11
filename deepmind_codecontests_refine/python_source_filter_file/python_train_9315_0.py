def is_valid_tile(r, c, n, m):
    return r >= 0 and c >= 0 and r < n and c < m

def gen_adjacents(r, c, n, m):
    adjs = []
    possibles = [(r + 1, c), (r - 1, c), (r, c + 1), (r, c - 1)]
    for possible in possibles:
        if is_valid_tile(*possible, n, m):
            adjs.append(possible)
    return adjs

def solve(table, r1, c1, r2, c2, n, m):
    if r1 == r2 and c1 == c2:
        adjacents = gen_adjacents(r1, c1, n, m)
        for adjacent in adjacents:
            if table[adjacent[0]][adjacent[1]] == ".":
                return True
        return n + m > 2
    if table[r2][c2] == ".":
        adjacents = gen_adjacents(r2, c2, n, m)
        solid = 0
        for adj in adjacents:
            if table[adj[0]][adj[1]] == ".":
                solid += 1
        if solid < 2:
            return solid == 1 and (r1, c1) in adjacents
    forward_visited = set([(r1, c1)]); backward_visited = set([(r2, c2)])
    forward_nodes = [(r1, c1)]; backward_nodes = [(r2, c2)]
    while forward_nodes and backward_nodes:
        for i in range(len(forward_nodes)):
            node = forward_nodes.pop(0)
            adjacents = gen_adjacents(*node, n, m)
            for adjacent in adjacents:
                if adjacent in backward_visited:
                    return True
                if adjacent not in forward_visited and table[adjacent[0]][adjacent[1]] == ".":
                    forward_visited.add(adjacent)
                    forward_nodes.append(adjacent)
        for j in range(len(backward_nodes)):
            node = backward_nodes.pop(0)
            adjacents = gen_adjacents(*node, n, m)
            for adjacent in adjacents:
                if adjacent in forward_visited:
                    return True
                if adjacent not in backward_visited and table[adjacent[0]][adjacent[1]] == ".":
                    backward_visited.add(adjacent)
                    backward_nodes.append(adjacent)
    return False

def main():
    n, m = map(int, input().split())
    table = []
    for _ in range(n):
        row = input()
        table.append(row)
    r1, c1 = map(int, input().split())
    r2, c2 = map(int, input().split())
    r1 -= 1; c1 -= 1; r2 -= 1; c2 -= 1
    if solve(table, r1, c1, r2, c2, n, m):
        print("YES")
    else:
        print("NO")
main()