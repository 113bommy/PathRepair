import sys
input = lambda : sys.stdin.readline().strip()
intput = lambda : map(int, input().split())

if __name__ == '__main__':
    A, queries = [], []
    f = [i for i in range(500001)]
    Q, = intput()
    for _ in range(Q):
        q = tuple(intput())
        queries.append(q)
    for q in reversed(queries):
        if q[0] == 1:
            A.append( f[q[1]] )
        if q[0] == 2:
            f[ q[1] ] = q[2]
    print(*A[::-1])
