import collections


def main():
    # n = int(input())
    x, y, z, t1, t2, t3 = list(map(int, input().split()))
    stair = t1 * abs(y - x)
    ele = t2 * (abs(y - x) + abs(z - x)) + 3 * t3
    print(stair, ele)
    print("YES" if ele <= stair else "NO")


main()
