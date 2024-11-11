def solution(t, c, P):
    cons = ret = 0
    for p in P:
        if p <= t:
            cons+=1
        else:
            cons=1
        if c <= cons:
            ret+=1
    return ret

n, t, c = map(int, input().split())
P = map(int, input().split())
print(solution(t, c, P))