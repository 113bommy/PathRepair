__author__ = 'Darren'


def solve():
    n, m = map(int, input().split())
    sheet = [input().strip() for _i in range(n)]
    while sheet[0] == '.' * m:
        sheet = sheet[1:]
    while sheet[-1] == '.' * m:
        sheet.pop()
    left = min([len(row.split('*')[0]) for row in sheet])
    right = min([len(row.split('*')[0]) for row in sheet])
    for row in sheet:
        print(row[left:m-right])


if __name__ == '__main__':
    solve()
