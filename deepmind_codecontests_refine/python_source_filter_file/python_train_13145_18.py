from sys import stdin, gettrace

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    r, c = map(int, inputi().split())
    costs = [int(a) for a in inputi().split()]
    if r >= 0:
        if c <= 0:
            o1 = costs[4] * (-c) + costs[5] * r
            o2 = costs[4] * (r - c) + costs[0] * r
            o3 = costs[3] * (-c) + costs[5] * (r - c)
        elif c <= r:
            o1 = costs[5] * (r - c) + costs[0] * c
            o2 = costs[5] * r + costs[1] * c
            o3 = costs[4] * (r - c) + costs[1] * r
        else:
            o1 = costs[0] * r + costs[1] * (c - r)
            o2 = costs[0] * c + costs[2] * (c - r)
            o3 = costs[5] * r + costs[1] * c
    else:
        if c >= 0:
            o1 = costs[1] * c + costs[2] * (-r)
            o2 = costs[1] * (c - r) + costs[3] * (-r)
            o3 = costs[0] * c + costs[2] * (c - r)
        elif c >= r:
            o1 = costs[2] * (c - r) + costs[3] * (-c)
            o2 = costs[2] * (-r) + costs[4] * (-c)
            o3 = costs[1] * (c - r) + costs[3] * (-r)
        else:
            o1 = costs[3] * (-r) + costs[4] * (r - c)
            o2 = costs[3] * (-c) + costs[5] * (r - c)
            o3 = costs[2] * (-r) + costs[4] * (-c)
    print(min(o1, o2, o3))


def main():
    t = int(inputi())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()
