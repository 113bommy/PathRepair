N, A, B, C, D = map(int, input().split())
S = input()
print('No' if '##' in S[A:C-1] or '##' in S[B:D-1] or C == D or C > D and '...' not in S[B-2:D] else 'Yes')
