# -*- coding: utf-8 -*-
"""
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0118
"""
import sys



def solve(data):
    size = len(data[0])
    data.insert(0, ['0' for _ in range(size)])
    data.insert(len(data), ['0' for _ in range(size)])

    processing_area = []
    area_id = 0
    for y in range(1, len(data)):
        for x in range(1, len(data[0])):
            print('y:{}, x:{}'.format(y, x))
            mark = data[y][x]
            data[y][x] = '0'
            if mark != '0':
                area_id += 1
                processing_area.append((y, x))

                while processing_area:
                    yy, xx = processing_area.pop()
                    if data[yy-1][xx] == mark:
                        data[yy-1][xx] = '0'
                        processing_area.append((yy-1, xx))
                    if data[yy+1][xx] == mark:
                        data[yy+1][xx] = '0'
                        processing_area.append((yy+1, xx))
                    if data[yy][xx-1] == mark:
                        data[yy][xx-1] = '0'
                        processing_area.append((yy, xx-1))
                    if data[yy][xx+1] == mark:
                        data[yy][xx+1] = '0'
                        processing_area.append((yy, xx+1))
                mark = '0'
    return area_id



def main(args):
    # data = []
    # data.append(['0', '#', '#', '#', '#', '*', '*', '*', '*', '*', '@', '0'])
    # data.append(['0', '@', '#', '@', '@', '@', '@', '#', '*', '#', '*', '0'])
    # data.append(['0', '@', '#', '#', '*', '*', '*', '@', '@', '@', '*', '0'])
    # data.append(['0', '#', '*', '*', '*', '*', '#', '*', '@', '*', '*', '0'])
    # data.append(['0', '#', '#', '@', '*', '#', '@', '@', '*', '#', '#', '0'])
    # data.append(['0', '*', '@', '@', '@', '@', '*', '@', '@', '@', '#', '0'])
    # data.append(['0', '*', '*', '*', '#', '@', '*', '@', '#', '#', '*', '0'])
    # data.append(['0', '*', '@', '@', '@', '*', '@', '@', '#', '#', '@', '0'])
    # data.append(['0', '*', '@', '*', '#', '*', '@', '#', '#', '*', '*', '0'])
    # data.append(['0', '@', '*', '*', '*', '*', '#', '@', '@', '#', '@', '0'])

    while True:
        h, w = [int(x) for x in input().split(' ')]
        if h == 0 and w == 0:
            break
        data = []
        for _ in range(w):
            temp = list(input())
            temp.insert(0, '0')
            temp.append('0')
            data.append(temp)

        result = solve(data)
        print(result)


if __name__ == '__main__':
    main(sys.argv[1:])