import math

def main():
    px, py, vx, vy, a, b, c, d = map(int, input().split())

    vectorx = vx / math.sqrt(math.pow(vx, 2) + math.pow(vy, 2))
    vectory = vy / math.sqrt(math.pow(vx, 2) + math.pow(vy, 2))

    print(px + (b * vectorx), py + (b * vectory))
    print(px - ((a / 2) * vectory), py - ((a / 2) * vectorx))
    print(px - ((c / 2) * vectory), py + ((c / 2) * vectorx))
    print(px - ((c / 2) * vectory) - (d * vectorx), py + ((c / 2) * vectorx) - (d * vectory))
    print(px + ((c / 2) * vectory) - (d * vectorx), py - ((c / 2) * vectorx) - (d * vectory))
    print(px + ((c / 2) * vectory), py - ((c / 2) * vectorx))
    print(px + ((a / 2) * vectory), py - ((a / 2) * vectorx))


if __name__ == '__main__':
    main()

