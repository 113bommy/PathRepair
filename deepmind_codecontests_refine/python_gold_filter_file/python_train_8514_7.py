S, T = input(), input()

def func(S, T):

    merge_S = list(set(S))
    merge_T = list(set(T))
    for t in merge_T:
        if t not in merge_S:
            return -1

    S_2 = S+S
    len_s = len(S)

    ans = -1

    for t in T:
        ans += S_2[(ans+1)%len_s:].index(t) + 1

    return ans + 1

print(func(S,T))