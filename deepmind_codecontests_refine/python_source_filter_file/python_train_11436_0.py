N = int(input())
S = input()

T = [+1 if s=='(' else -1 for s in S]

from itertools import accumulate
Tcumsum = list(accumulate(T))

i = - min(Tcumsum)

print('(' * i + S + ')' * (Tcumsum[-1]+i))