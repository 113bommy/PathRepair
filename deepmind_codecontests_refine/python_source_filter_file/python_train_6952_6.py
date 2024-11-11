# E - Three Substrings

a = list(input())
b = list(input())
c = list(input())

A, B, C = len(a), len(b), len(c)

M = max(A, B, C)
cons = 6*M
a_not_match_b = [False] * 2 * cons
b_not_match_c = [False] * 2 * cons
a_not_match_c = [False] * 2 * cons

def fill_match_list(d1, d2, l):
    for i in range(len(d1)):
        for j in range(len(d2)):
            if d1[i] != d2[j] and d1[i] != "?" and d2[j] != "?":
                l[j-i+cons] = True
    return l

a_not_match_b = fill_match_list(a, b, a_not_match_b)
b_not_match_c = fill_match_list(b, c, b_not_match_c)
a_not_match_c = fill_match_list(a, c, a_not_match_c)

ans = 3*M
for b_idx in range(-2*M, 2*M):
    for c_idx in range(-2*M, 2*M):
        if not a_not_match_b[b_idx + cons] and not a_not_match_c[c_idx + cons] and not b_not_match_c[c_idx - b_idx + cons]:
            ans = min(ans, max(A, B + b_idx, C + c_idx) - min(0, b_idx, c_idx))

print(ans)