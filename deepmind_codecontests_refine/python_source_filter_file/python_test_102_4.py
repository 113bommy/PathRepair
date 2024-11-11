from sys import stdin

def main():
    moves = {"L":(0,-1),"R":(0,1),"D":(1,0),"U":(-1,0)}
    input = stdin.readline
    t = int(input())
    for _ in range(t):
        n,m = [int(i) for i in input().split()]
        commands = input().strip()
        cur = [1,1]
        # ma = U D L R
        ma = [(1,1), (1,1), (1,1), (1,1)]
        for move in commands:
            cur[0] += moves[move][0]; cur[1] += moves[move][1]
            tc = tuple(cur)
            h = max(ma[1][0],tc[0]) - min(ma[0][0],tc[0])
            w = max(ma[3][1],tc[1]) - min(ma[2][1],tc[1])
            if n <= h or m <= w:
                break
            if cur[0] < ma[0][0]:
                ma[0] = tc
            if cur[0] > ma[1][0]:
                ma[1] = tc
            if cur[1] < ma[2][0]:
                ma[2] = tc
            if cur[1] > ma[3][0]:
                ma[3] = tc
        print(1 + max(0,1-ma[0][0]), 1 + max(0, 1-ma[2][1]))


if __name__ == '__main__':
    main()