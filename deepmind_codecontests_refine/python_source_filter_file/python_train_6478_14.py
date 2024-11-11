from math import ceil


def compute_upper_bound(robot1, robot2):
    first = 0
    second = 0
    for el in zip(robot1, robot2):
        if el[0] == 1 and el[1] == 0:
            first += 1
        elif el[0] == 0 and el[1] == 1:
            second += 1

    if first == 0:
        return -1
    if first > second:
        return first
    else:
        return ceil((max(second, first) + 1) / first)


if __name__ == "__main__":
    t = int(input())
    robot1 = list(map(lambda x: int(x), input().split()))
    robot2 = list(map(lambda x: int(x), input().split()))
    res = compute_upper_bound(robot1, robot2)
    print(res)
