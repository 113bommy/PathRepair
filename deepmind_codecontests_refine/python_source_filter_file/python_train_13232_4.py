import configparser
import sys
input = sys.stdin.readline


def ceil_div(x, y):
    return -(-x // y)

def main():
    n, m, l = [int(x) for x in input().split(' ')]
    a = [int(x) for x in input().split(' ')]

    i = 0
    cnt = 0

    part = [False for i in range(n)]

    while i < len(a):
        while i < len(a) and a[i] <= l:
            i += 1

        if i == len(a):
            break

        while i < len(a) and a[i] > l:
            part[i] = True
            i += 1

        cnt += 1

    for i in range(m):
        p = [int(x) for x in input().split(' ')]

        if p[0] == 0:
            print(cnt)
        else:
            hair = p[1]-1
            grow = p[2]

            a[hair] += grow

            if part[hair] or a[hair] < l:
                continue

            part[hair] = True

            if n == 1:
                cnt += 1
                continue

            if hair == 0:
                if not part[hair+1]:
                    cnt += 1
            elif hair == n-1:
                if not part[hair-1]:
                    cnt += 1
            else:
                if not part[hair-1] and not part[hair+1]:
                    cnt += 1
                elif part[hair-1] and part[hair+1]:
                    cnt -= 1



if __name__ == '__main__':
    main()
