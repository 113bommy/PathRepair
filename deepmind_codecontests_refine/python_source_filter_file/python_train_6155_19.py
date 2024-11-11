bk = int(input())
dr,dc = list(map(int, input().split()))
ws = (dr-1 + dc-1) / 2
bs = (bk-dr + bk-dc) / 2
if ws <= bs:
    print('White')
else:
    print('Black')