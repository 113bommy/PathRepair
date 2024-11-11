def solve(n, k, l, c, d, p, nl, np):
    drinks_count = min((k * l) / nl, c * d)
    salts_count = p / np
    toasts_count = min(drinks_count, salts_count)

    return int(toasts_count / n)


if __name__ == "__main__":
    n, k, l, c, d, p, nl, np = map(int, input().split(" "))
    print(solve(n, k, l, c, d, p, nl, np))