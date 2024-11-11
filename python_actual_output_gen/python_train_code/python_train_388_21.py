def maxmax(numbers):
    maxn = len(numbers)
    m1 = 0
    m2 = 0
    for i, n in enumerate(numbers):
        if n == 1:
            m1 = i
        elif n == maxn:
            m2 = i
    m1 = max(m1 - 1, (maxn - m1 - 1))
    m2 = max(m2 - 1, (maxn - m2 - 1))
    return max(m1, m2)


def solve(instr):
    return maxmax(list(map(int, instr.split(" "))))

_ = input()
print(solve(input()))
