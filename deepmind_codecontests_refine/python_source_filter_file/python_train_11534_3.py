import collections
import sys

sys.setrecursionlimit(10 ** 6)

N = int(input())
colors = [int(x) - 1 for x in input().split()]
neighbors = collections.defaultdict(list)
for i in range(N - 1):
    a, b = map(int, input().split())
    neighbors[a - 1].append(b - 1)
    neighbors[b - 1].append(a - 1)

subtree_sizes = [0] * N


def calc_sizes(node, parent):
    size = 1
    for i in neighbors[node]:
        if i != parent:
            size += calc_sizes(i, node)
    subtree_sizes[node] = size
    return size


calc_sizes(0, -1)
components = {c: {0: N} for c in range(N)}
components[colors[0]] = {}
color_stack = {c: [0] for c in range(N)}
color_stack[colors[0]] = []


def calc_components(node, parent):
    color_stack_pushed = False
    if parent >= 0 and colors[parent] != colors[node]:
        color_parent = color_stack[colors[node]][-1]
        components[colors[node]][color_parent] -= subtree_sizes[node]
        components[colors[parent]][node] = subtree_sizes[node]
        color_stack[colors[parent]].append(node)
        color_stack_pushed = True
    for i in neighbors[node]:
        if i != parent:
            calc_components(i, node)
    if color_stack_pushed:
        color_stack[colors[parent]].pop()


calc_components(0, -1)


def count_paths(n):
    return n * (n + 1) // 2


total_paths = count_paths(subtree_sizes[0])
for c in range(N):
    print(total_paths - sum(count_paths(size) for size in components[c].values()))
