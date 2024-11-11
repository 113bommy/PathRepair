def sum_of_digits(nr):
    s = 0
    while nr > 0:
        s += nr % 10
        nr //= 10
    return s


def main():
    n = int(input())
    solutions = []
    for s in range(154):
        delta = (s ** 2 + 4 * n) ** 0.5
        x = (-s + delta)/2
        if int(x) != x:
            continue
        x = int(x)
        if sum_of_digits(x) == s: # and x ** 2 + sum_of_digits(x) * x - n == 0:
            solutions.append(x)
    if solutions:
        print(min(solutions))
    else:
        print(-1)


if __name__ == "__main__":
    main()
