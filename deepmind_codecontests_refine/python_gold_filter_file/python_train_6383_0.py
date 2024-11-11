'''
Author: your name
Date: 2021-04-25 16:21:07
LastEditTime: 2021-04-25 16:36:45
LastEditors: Please set LastEditors
Description: In User Settings Edit
FilePath: \code_py\cf_718C.py
'''


def main():
    n = int(input())
    p = list(map(int, input().split()))
    m = [[0]*n for i in range(n)]
    for i in range(n):
        pi = p[i]
        x, y = i, i
        m[x][y] = pi
        for j in range(p[i]-1):
            if m[x][y-1] == 0 and y-1 >= 0:
                y -= 1
            elif m[x+1][y] == 0 and x+1 < n:
                x += 1
            else:
                ans = -1
                print(ans)
                exit()
            m[x][y] = pi

    for i in range(n):
        for j in range(i+1):
            print(m[i][j], end=' ')
        print()


if __name__ == '__main__':
    main()
