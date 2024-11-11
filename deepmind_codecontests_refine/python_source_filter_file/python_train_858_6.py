import sys
import threading
sys.setrecursionlimit(10**5 + 5)
threading.stack_size(10**7)


def main():
    t = int(input())

    for _ in range(t):
        n = int(input())

        adj = [[] for _  in range(n)]
        
        for _ in range(n - 1):
            u, v = [int(x) - 1 for x in input().split()]
            adj[u].append(v)
            adj[v].append(u)

        max_size = [0] * n
        compute_sizes(0, -1, max_size, adj)

        min_max_size = min(max_size)
        centroids = [i for i, s in enumerate(max_size) if s == min_max_size]

        if len(centroids) == 1:
            print(f'1 {adj[0][0] + 1}')
            print(f'1 {adj[0][0] + 1}')
        else:
            c1, c2 = centroids
            u = adj[c1][0]
            if u == c2:
                u = adj[c1][1]
            print(f'{c1 + 1} {u + 1}')
            print(f'{c2 + 1} {u + 1}')


def compute_sizes(u, p, max_size, adj):
    size = 1

    for v in adj[u]:
        if v != p:
            subtree_size = compute_sizes(v, u, max_size, adj)
            max_size[u] = max(max_size[u], subtree_size)
            size += subtree_size
    
    max_size[u] = max(max_size[u], len(adj) - size)
    return size


if __name__ == '__main__':
    threading.Thread(target=main).start()
