from sys import stdin, stdout

MOD = 998244353


def solve_test(n, elements):
    dp_increasing = [0] * (n + 1)
    dp_alternate = [0] * (n + 1)
    # dp_alternate[i] = # subsequences that alternate with mex value equal to i
    # 0 1 2 3 4 .. x-2 x

    for x in elements:
        dp_increasing[x] = dp_increasing[x] * 2  # 0 1 2 .. x | add x
        if x >= 1:
            dp_increasing[x] = dp_increasing[x] + dp_increasing[x - 1]  # 0 1 2 3 .. x-1 | add x
        if x == 0:
            dp_increasing[x] = dp_increasing[x] + 1  # we have subsequence of length 1 for [0]
        dp_increasing[x] %= MOD
        if x >= 1:
            dp_alternate[x - 1] = dp_alternate[x - 1] * 2  # just add 2 to 0 2 2 2 2
        if x >= 2:
            dp_alternate[x - 1] = dp_alternate[x - 1] + dp_increasing[x - 2]
        if x + 1 < n + 1:
            dp_alternate[x + 1] = (dp_alternate[x + 1] * 2) % MOD
            # 0 1 2 .. x - 2 | add x ( from another sequence
        if x == 1:
            dp_alternate[x - 1] = dp_alternate[x - 1] + 1  # we can have [1]
        dp_alternate[x] %= MOD
    answer = [(x + y) % MOD for x, y in zip(dp_increasing, dp_alternate)]
    return sum(answer)


def stress_test():
    n = int(1e5)
    elements = [i for i in range(n)]
    solve_test(n, elements)


def read_input():
    tests = int(stdin.readline())
    for test in range(tests):
        n = int(stdin.readline())
        elements = [int(x) for x in stdin.readline().split()]
        stdout.write(str(solve_test(n, elements)) + '\n')


def read_file():
    with open("input.txt") as f:
        tests = int(f.readline())
        for test in range(tests):
            n = int(f.readline())
            elements = [int(x) for x in f.readline().split()]
            print(solve_test(n, elements))


# Press the green button in the gutter to run the script.
if __name__ == '__main__':
    read_input()
