s1, s2 = input(), input()
L1, L2 = len(s1), len(s2)

D = set()
for d in range(1, int(L1 ** .5) + 1):
    if L1 % d == 0:
        D |= {d, L1 // d}

S = [s1[:d] for d in D if s1[:d] * (L1//d) == s1]

print(sum(s * (L2//len(s)) == s2 for s in S))