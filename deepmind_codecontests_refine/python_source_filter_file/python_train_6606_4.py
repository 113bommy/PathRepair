import sys

input = sys.stdin.readline


def inp():
    return (int(input()))


def inlt():
    return (list(map(int, input().split())))


def insr():
    s = input()
    return (list(s[:len(s) - 1]))


def invr():
    return list((map(int, input().split())))

hash_map = {}


def solve(i, cur_sum):

    if i == len(s2):
        if cur_sum == total:
            return 1
        return 0
    if (i, cur_sum) in hash_map:
        return hash_map[(i, cur_sum)]
    count = 0
    if s2[i] == "?":
        for k in [1, -1]:
            count += solve(i+1, cur_sum + k)
    elif s2[i] == "+":
        count += solve(i+1, cur_sum + 1)
    else:
        count += solve(i+1, cur_sum - 1)
    hash_map[(i, cur_sum)] = count
    return count


if __name__ == '__main__':
    s1 = insr()
    s2 = insr()

    total = 0
    q_count = 0
    for c in s1:
        if c == "+":
            total += 1
        else:
            total -= 1
    for c in s2:
        if c == "?":
            q_count += 1

    res = solve(0, 0)
    if res == 0 or q_count == 0:
        print(res)
    else:
        print(res/(q_count * 2))
