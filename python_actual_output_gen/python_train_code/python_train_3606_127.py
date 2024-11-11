N, A, B, C, D = map(int, input().split())
S = input()
if '##' in S[A-1:max(C, D)]:
    print('No')
elif C < D or ('...' in S[B-1:D]):
    print('Yes')
else:
    print('No')
