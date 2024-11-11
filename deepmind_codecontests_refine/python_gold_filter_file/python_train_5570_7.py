from collections import defaultdict
from sys import setrecursionlimit
import threading


def solve(current, parent, cats):
    global out
    if cats > m: return 0
    leaf = 1
    for adj in e[current]:
        if adj != parent:
            leaf = 0
            solve(adj, current, cats*a[adj] + a[adj])
    out += leaf
 

def read_input():
    global n, m, a, e
    n, m = list(map(int, input().split()))
    a = list(map(int, input().split()))
    e = defaultdict(list)
    for _ in range(n-1):
        u, v = list(map(int, input().split()))
        u -= 1
        v -= 1
        e[u].append(v)
        e[v].append(u)


def main():
    global n, m, a, e, out
    out = 0
    read_input()
    solve(0, -1, a[0])
    print(out)


threading.stack_size(60*10**6)
setrecursionlimit(10**5 + 100)
threading.Thread(target=main).start()
