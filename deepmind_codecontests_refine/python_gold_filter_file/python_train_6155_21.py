bk = int(input())
dr,dc = list(map(int, input().split()))
ws = (dr-1 + dc-1)
bs = (bk-dr + bk-dc)
if ws <= bs:
    print('White')
else:
    print('Black')