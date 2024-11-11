import time


def main():
    modulo = 10 ** 9 + 7
    divs = (
        2, 6, 12, 60, 60, 420, 840, 2520, 2520, 27720, 27720, 360360, 360360, 360360, 720720, 12252240, 12252240,
        232792560,
        232792560, 232792560, 232792560, 5354228880, 5354228880, 26771144400, 26771144400, 80313433200, 80313433200,
        2329089562800, 2329089562800, 72201776446800, 144403552893600, 144403552893600, 144403552893600,
        144403552893600,
        144403552893600, 5342931457063200, 5342931457063200, 5342931457063200, 5342931457063200)

    t = i_input()
    for tt in range(t):
        n = i_input()
        out = n * 2

        for div in divs:
            out += n // div
            if div > n:
                break
        print(out % modulo)


############

def i_input():
    return int(input())


def l_input():
    return input().split()


def li_input():
    return list(map(int, l_input()))


def il_input():
    return list(map(int, l_input()))


# endregion

if __name__ == "__main__":
    TT = time.time()
    main()
    # print("\n", time.time() - TT)
