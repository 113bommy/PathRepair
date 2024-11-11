import sys
from functools import lru_cache
from collections import defaultdict

def query(i, j):
    '''
    Returns the number of white and number of black squares
    in [i, j] inclusive.
    '''
    if i == 0:
        black = cum_cols[j]
    else:
        black = cum_cols[j] - cum_cols[i - 1]
    white = (j - i + 1) * len(mat) - black
    return (black, white)

def main(x, y):
    num_cols = len(mat[0])

    DP = {}
    def dp(j, color):
        if j >= num_cols:
            return 0
        return DP[(j, color)]

    for j in range(num_cols - x, -1, -1):
        bb = float("inf")
        bw = float("inf")
        for p in range(x, y + 1):
            if j + p - 1 >= num_cols:
                continue
            b, w = query(j, j + p - 1)
            bb = min(bb, w + dp(j + p, 'w'))
            bw = min(bb, b + dp(j + p, 'b'))
        DP[(j, 'b')] = bb
        DP[(j, 'w')] = bw
    return min(dp(0, 'b'), dp(0, 'w'))

if __name__ == "__main__":
    mat = []
    for e, line in enumerate(sys.stdin.readlines()):
        if e == 0:
            _, _, x, y = map(int, line.strip().split())
        else:
            mat.append([c for c in line.strip()])

    cols = [0 for _ in range(len(mat[0]))]
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if mat[i][j] == '#':
                cols[j] += 1

    cum_cols = [cols[0]]
    for i in range(1, len(cols)):
        cum_cols.append(cum_cols[-1] + cols[i])
    print(main(x, y))
