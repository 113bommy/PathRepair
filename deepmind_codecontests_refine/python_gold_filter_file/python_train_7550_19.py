def main():
    n = int(input())
    s = list(input())

    if n > 26:
        print(-1)
    else:
        res = 0
        for e in set(s):
            res += s.count(e) - 1
        print(res)

if __name__ == '__main__':
    main()
