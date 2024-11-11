import bisect

def main():
    S = input()
    dS = {c : [] for c in 'abcdefghijklmnopqrstuvwxyz'}

    for i, s in enumerate(S):
        dS[s].append(i)

    #

    T = input()
    ans = 0

    p = 0

    for t in T:
        if not dS[t]:
            print(-1)
            return
        if dS[t][-1] < p:
            p = 0
            ans += len(S)
        idx = bisect.bisect_left(dS[t], p)
        p = dS[t][idx] + 1
    
    print(ans + p)

main()

