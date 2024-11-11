from sys import setrecursionlimit
setrecursionlimit(10000000)

def solve():
    N = int(input())
    adj = [list() for _ in range(N)]
    for _ in range(N-1):
        a,b = map(int,input().split())
        adj[a-1].append(b-1)
        adj[b-1].append(a-1)

    # path
    goal = N-1
    path = [0]
    candidates = [adj[0]]
    while path[-1] != goal:
        while not candidates[-1]:
            candidates.pop()
            path.pop()
        u = candidates[-1].pop()
        candidates.append([n for n in adj[u] if n != path[-1]])
        path.append(u)


    black = path[(len(path)-1)//2]
    white = path[(len(path)-1)//2+1]

    # count
    path = [black]
    candidates = [[n for n in adj[black] if n != white]]
    cnt = 0
    try:
        while True:
            while not candidates[-1]:
                cnt += 1
                candidates.pop()
                path.pop()
            u = candidates[-1].pop()
            candidates.append([n for n in adj[u] if n != path[-1]])
            path.append(u)
    except IndexError:
        pass
    bscore = cnt
    print('Fennec' if bscore*2 > N else 'Snuke')

if __name__ == '__main__':
    solve()