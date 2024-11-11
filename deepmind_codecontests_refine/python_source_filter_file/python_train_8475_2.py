def main():
    h = int(input())
    l = [c == '#' for _ in range(h) for c in input()]
    if not (l[0] or l[-1] or sum(l) % 5):
        l[-1] = True
        w, idx = len(l) // h, 0
        lim = (h - 2) * w - 2
        pattern = (0, w - 1, w, w + 1, 2 * w)
        while True:
            idx = l.index(True, idx + 1)
            if idx > lim:
                break
            if all(l[_ + idx] for _ in pattern):
                for _ in pattern:
                    l[_ + idx] = False
            else:
                break
    l[-1] = False
    print(('YES', 'NO')[any(l)])


if __name__ == '__main__':
    main()