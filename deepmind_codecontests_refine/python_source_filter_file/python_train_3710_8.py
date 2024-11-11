

def main():
    buff = input().split()
    h1, a1, c1 = int(buff[0]), int(buff[1]), int(buff[2])
    buff = input().split()
    h2, a2 = int(buff[0]), int(buff[1])

    strategy = []
    while h2 > 0:
        if h1 - a2 <= 0 and h2 - a1 >= 0:
            strategy.append("HEAL")
            h1 += (c1 - a1)
        else:
            strategy.append("STRIKE")
            h2 -= a1
            h1 -= a2
    return "{}\n{}".format(len(strategy), "\n".join(strategy))


if __name__ == "__main__":
    print(main())
