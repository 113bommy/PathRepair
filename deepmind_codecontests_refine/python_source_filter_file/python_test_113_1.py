def solve_test():
    x1, p1 = map(int, input().split(" "))
    x2, p2 = map(int, input().split(" "))
    minimum = min(p1,p1)
    p1 -= minimum
    p2 -= minimum
    if p1 >= 7:
        return ">"
    if p2 >= 7:
        return "<"
    for _ in range(p1):
       x1 *= 10
    for _ in range(p2):
        x2 *= 10
    if x1 < x2:
        return "<"
    elif x1 == x2:
        return "="
    else:
        return ">"


def main():
    tests = int(input())
    for _ in range(tests):
        answer = solve_test()
        print(answer)


if __name__ == "__main__":
    main()
