import sys
sys.setrecursionlimit(10 ** 8)
INF = 10 ** 10

class edge:
    def __init__(self, fr, to, cost): self.fr, self.to, self.cost = fr, to, cost

def input(): return sys.stdin.readline().strip()
def Z(): return int(input())
def ZZ(): return [int(_) for _ in input().split()]

def main():
    N, M, P = ZZ()
    es = []
    for _ in range(M):
        a, b, c = ZZ()
        a -= 1
        b -= 1
        es.append(edge(a, b, -(c-P)))

    d = [INF] * N
    d[0] = 0
    for i in range(N-1):
        for e in es:
            if d[e.fr] != INF and d[e.to] > d[e.fr] + e.cost:
                d[e.to] = d[e.fr] + e.cost
    n = [False] * N
    for i in range(N):
        for e in es:
            if d[e.fr] != INF and d[e.to] > d[e.fr] + e.cost:
                d[e.to] = d[e.fr] + e.cost
                n[e.to] = True
            if n[e.fr] == True: n[e.to] = True
    print(-1 if n[N-1] else max(0, -d[N-1]))

    return

if __name__ == '__main__':
    main()
