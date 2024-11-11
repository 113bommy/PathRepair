import heapq

def main():
    N, Q = map(int, input().split())
    STX = [tuple(map(int, input().split())) for _ in range(N)]
    ev = []
    for s, t, x in STX:
        ev.append((s - x, True, x))
        ev.append((t - x, False, x))
    ev.sort(reverse=True)
    bar = []
    dead = {}

    for d in [int(input()) for _ in range(Q)]:
        while ev and ev[-1][0] <= d:
            t, a, x = ev.pop()
            if a:
                heapq.heappush(bar, x)
            else:
                dead[x] = dead.get(x, 0) + 1
                while bar and bar[0] in dead:
                    x = heapq.heappop(bar)
                    if dead[x] == 0:
                        del dead[x]
                    else:
                        dead[x] = dead[x] - 1
        print(bar[0] if bar else -1)

main()
