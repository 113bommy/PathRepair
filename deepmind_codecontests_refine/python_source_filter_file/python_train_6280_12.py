from math import ceil


def minSteps(S):
    new_str = ""
    N = len(S)
    i = 0
    while i < N:
        new_str += S[i]
        j = i
        while i < N and S[i] == S[j]:
            i += 1
    return ceil((len(new_str) + 1) / 2)


if __name__ == '__main__':
    t = int(input())
    for _ in range(t):
        n, a, b = map(int, input().split())
        s = input()
        S = "100111"
        if b>a:
            print(a * n + minSteps(s) * b)
        else:
            print(a * n + n * b)
