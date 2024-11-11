def solve():
    splitted_intput = [int(x) for x in input().split(" ")]
    a, b, c, d = splitted_intput
    print(c, c, b)


def main():
    T = int(input())
    for i in range(T):
        solve()


if __name__ == "__main__":
    main()

"""
4
1 3 5 7
1 5 5 7
100000 200000 300000 400000
1 1 977539810 977539810
"""
