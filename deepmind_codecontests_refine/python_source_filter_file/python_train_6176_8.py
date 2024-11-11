def read():
    return map(int, input().split())


def make_step(pos, end, d):
    if d > 0:
        res = (end - pos) // d
    elif d < 0:
        res = - (pos - 1) // d
    else:
        res = float('infinity')

    return res


def main():
    n, m = read()
    xc, yc = read()
    k = int(input())
    ans = 0
    for _ in range(k):
        dx, dy = read()
        stepx = make_step(xc, m, dx)
        stepy = make_step(yc, n, dy)
        num_steps = min(stepx, stepy)
        ans += num_steps
        xc += num_steps * dx
        yc += num_steps * dy

    print(ans)


if __name__ == "__main__":
    main()
