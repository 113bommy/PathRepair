N, A, B, C, D = map(int, input().split())
A, B, C, D = A-1, B-1, C-1, D-1
S = input()

if C > D:
    print('Yes' if '...' in S[B-1:D+1] and '##' not in S[A:C] else 'No')
else:
    print('Yes' if '##' not in S[A:D] else 'No')