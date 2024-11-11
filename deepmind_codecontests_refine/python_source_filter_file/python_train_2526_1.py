import sys
sys.setrecursionlimit(10**5)

def search(tree, cur, find, was):
    was.add(cur)
    for i in tree[cur]:
        if i == find:
            return 1, True
        elif not i in was:
            a = search(tree, i, find, was)
            if a[1]:
                return a[0] + 1, a[1]
    return -1, False

def max_depth(tree, cur, was_2):
    was_2.add(cur)
    dist = 0
    dot = cur
    for i in tree[cur]:
        if not i in was_2:
            new_dist, new_dot = max_depth(tree, i, was_2)
            if max(new_dist, dist) == new_dist:
                dist = max(new_dist, dist)
                dot = new_dot

    return dist + 1, dot

def main():
    was = set()
    was_2 = set()
    n, a, b, da, db = map(int, input().split())
    tree = dict()
    for i in range(1, n):
        u, v = map(int, input().split())
        if not u in tree:
            tree[u] = set()
        if not v in tree:
            tree[v] = set()
        tree[u].add(v)
        tree[v].add(u)
    dist = search(tree, a, b, was)
    far, dot = max_depth(tree, a, was_2)
    was_2 = set()
    ln = max_depth(tree, dot, was_2)
    if dist[0] <= da or db <= 2*da or ln[0] <= 2*da:
        print("Alice")
        return
    else:
        print("Bob")
        return

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        main()
"""
60, 61
"""
"""
"""
