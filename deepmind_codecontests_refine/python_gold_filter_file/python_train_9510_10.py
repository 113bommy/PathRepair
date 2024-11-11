def main():
    input()
    l = list(map(int, input().split()))
    m = min(l)
    print('Still Rozdil' if l.count(m) > 1 else l.index(m) + 1)


if __name__ == '__main__':
    main()
