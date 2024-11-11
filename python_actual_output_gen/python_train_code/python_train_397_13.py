n, m = [int(i) for i in input().split()]
S = input()
Q = [[i for i in input().split()] for j in range(m)]

def solve(i):
    cur = i
    for t, d in Q:
        if S[cur] == t:
            cur += 1 if d == 'R' else -1
        if cur < 0 or cur >= n:
            return False
    return True

def b_search(ok, ng):
    while abs(ok - ng) > 1:
        mid = (ok + ng) // 2
        if solve(mid):
            ok = mid
        else:
            ng = mid
    return ok

print(b_search(-1, n) - b_search(n, -1) + 1)