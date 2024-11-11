__author__ = 'aste'


def main():
    n, m, k = map(int, input().split())

    rows = [(0, 0)] * n
    cols = [(0, 0)] * m
    for i in range(0, k):
        op, rc, a = map(int, input().split())
        if op == 1:
            rows[rc - 1] = (a, i)
        else:
            cols[rc - 1] = (a, i)

    for i in range(0, n):
        for j in range(0, m):
            row = rows[i]
            col = cols[j]
            if row[1] < col[1]:
                print(col[0], end=' ')
            else:
                print(row[0], end=' ')
        print()

main()
