def main():
    import sys
    input = sys.stdin.readline
    sys.setrecursionlimit(10**6)
    t = int(input())
    for _ in range(t):
        N, M = [int(x) for x in input().strip().split()]
        g = [0] * N
        zero_columns = [0] * M
        zero_rows = 0
        for n in range(N):
            g[n] = [int(x) for x in input().strip().split()]
            if sum(g[n]) == 0:
                zero_rows += 1
            for m in range(M):
                if g[n][m] == 1:
                    zero_columns[m] = 1

        if min(zero_rows, sum(zero_columns)) % 2 == 1:
            print('Ashish')
        else:
            print('Vivek')

if __name__ == '__main__':
    main()