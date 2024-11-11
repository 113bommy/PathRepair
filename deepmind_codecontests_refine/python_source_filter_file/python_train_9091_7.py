from math import sqrt

if __name__ == '__main__':
    x1, y1, r1 = [int(x) for x in input().split()]
    x2, y2, r2 = [int(x) for x in input().split()]

    diff = sqrt((x1-x2) ** 2 + (y1-y2) ** 2) / 2
    l = [diff, r1/2,r2/2]
    l.sort()
    print(l[2] - l[1] - l[0])