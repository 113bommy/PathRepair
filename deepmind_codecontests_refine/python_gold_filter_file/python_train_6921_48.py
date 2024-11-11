def main():
    input()
    tot = res = 0
    for t in sorted(map(int, input().split())):
        if t >= tot:
            res += 1
            tot += t
    print(res)


if __name__ == '__main__':
    main()
