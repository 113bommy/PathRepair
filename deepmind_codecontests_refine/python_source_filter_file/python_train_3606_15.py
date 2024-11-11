from math import sqrt


def solve(a, n):
    max_val = -100000000000000
    for i in a:
        if i <= 0:
            if i > max_val:
                max_val = i
        elif not sqrt(i).is_integer() and i > max_val:
            max_val = i
    return max_val


def main():
    # vars = list(map(int, input().split(" ")))
    n = int(input())
    a = list(map(int, input().split(" ")))
    # b = list(map(int, input().split(" ")))
    # for i in range(n):
    #     arr.append(list(map(int, list(input()))))
    print(solve(a, n))


main()
