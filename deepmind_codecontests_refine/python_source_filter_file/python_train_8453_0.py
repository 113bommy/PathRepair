import sys

for _ in range(int(input())):
    r, c = map(int, input().split())
    a = [[] for _ in range(r)]
    row_count = [0]*r
    a_total = 0
    for y in range(r):
        a[y] = [1 if c == 'A' else 0 for c in sys.stdin.readline().rstrip()]
        row_count[y] = sum(a[y])
        a_total += row_count[y]

    if a_total == r*c:
        print(0)
        continue
    if a_total == 0:
        print('MORTAL')
        continue

    col_count = [0]*c
    for x in range(c):
        for y in range(r):
            col_count[x] += a[y][x]

    if row_count[0] == c or row_count[-1] == c or col_count[0] == r or col_count[-1] == r:
        print(1)
        continue
    if a[0][0] | a[0][-1] | a[-1][0] | a[-1][-1] == 1:
        print(2)
        continue
    if any(rcnt == r for rcnt in row_count) or any(ccnt == c for ccnt in col_count):
        print(2)
        continue
    if row_count[0] or row_count[-1] or col_count[0] or col_count[-1]:
        print(3)
        continue
    print(4)
