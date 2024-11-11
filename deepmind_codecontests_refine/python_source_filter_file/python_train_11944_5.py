inp = input().split()

N, P = int(inp[0]), int(inp[1])
S_prim = input()

S = []

for l in S_prim:
    S.append(l)

period_free = False

for p in range(0, P):

    liz = []
    p_safe = p

    while p < N:

        liz.append(S[p])
        p += P

    if len(liz) > 1 and ('.' in liz or ('1' in liz and '0' in liz)):
        period_free = True

##    adder = '.'
##
##    if '1' in liz:
##        adder = '0'
##
##    if '0' in liz:
##        adder = '1'    

if not period_free:

    print('No')

else:

    reversal = ['1', '0']

    for i in range(0, N):

        if S[i] == '.':

            if i - P >= 0:

                if S[i-P] != '.':

                    S[i-P] = reversal[int(S[i-P])]

            if i + P < N:

                if S[i+P] != '.':

                    S[i+P] = reversal[int(S[i+P])]

            if S[i] == '.':
                S[i] = '0'

    for l in S:
        print(l, end='')

    print()

        
