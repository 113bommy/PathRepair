
def solve(s):
    left_gt = s.find('>')
    right_lt = s.rfind('<')

    if left_gt == -1:
        return 0

    if right_lt == -1:
        return 0

    if left_gt < right_lt:
        return min(left_gt, len(s) - right_lt + 1)

    return min(right_lt + 1, len(s) - left_gt)


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        s = input()
        print(solve(s))
