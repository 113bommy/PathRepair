if __name__ == '__main__':
    poss = [2, 7, 2, 3, 3, 3, 2, 5, 1, 2]

    n = input()

    p = 1

    for d in n:
        p *= poss[int(d)]

    print(p)