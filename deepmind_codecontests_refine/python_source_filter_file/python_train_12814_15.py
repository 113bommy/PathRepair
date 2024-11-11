def main():
    _, s, t, r = int(input()), list(input()), input(), []
    try:
        for i, c in enumerate(t):
            if c == s[i]:
                continue
            j = i
            while s[j] != c:
                j += 1
            s.insert(i, s.pop(j))
            r += range(i + 1, j + 1)
        print(len(r), ' '.join(map(str, r)), sep='\n')
    except IndexError:
        print(-1)


if __name__ == '__main__':
    main()
