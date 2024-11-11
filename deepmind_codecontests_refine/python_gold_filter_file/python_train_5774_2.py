"""http://codeforces.com/problemset/problem/462/A"""

def solve(board):
    max_height = len(board)
    max_width = len(board[0])
    for i, row in enumerate(board):
        for j, cell in enumerate(row):
            count = 0
            # if board[i][j] == 'o':
            #     continue
            # print('----')
            for o in range(i-1, i+2):
                for p in range(j-1, j+2):
                    # print(o, p)
                    if o < 0 or o >= max_height:
                        continue
                    if p < 0 or p >= max_width:
                        continue
                    if o == i and p == j:
                        continue
                    if abs(i - o) + abs(j - p) == 1 and board[o][p] == 'o':
                        count += 1
            if count & 1:
                # print(i, j, count)
                return 'NO'
    return 'YES'

if __name__ == '__main__':
    n = int(input())
    b = []
    for i in range(n):
        b.append(input())
    print(solve(b))
