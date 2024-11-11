N, A, B, C, D = map(int, input().split())
S = '.' + input()


def solve():
    if '##' in S[A:C + 1] or '##' in S[B:D + 1]:
        return 'No'

    if C > D:
        if '...' not in S[B:D + 1]:
            return 'No'

    return 'Yes'


print(solve())
