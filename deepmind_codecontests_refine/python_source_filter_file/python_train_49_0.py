def ex(values):
    e = None
    for i, v in enumerate(values):
        e_ = f'({v//2}*((1-abs(t-{i}))+abs(1-abs(t-{i}))))'
        if e is None:
            e = e_
        else:
            e = f'({e}+{e_})'
    return e


def solve(circles):
    xs = [c[0] for c in circles]
    ys = [c[1] for c in circles]
    return ex(xs), ex(ys)


def pc(line):
    t = tuple(map(int, line.split()))
    assert len(t) == 3, f"Invalid circle: {line}"
    return t


def main():
    n = int(input())
    circles = [pc(input()) for _ in range(n)]
    f, g = solve(circles)
    print(f)
    print(g)


if __name__ == '__main__':
    main()
