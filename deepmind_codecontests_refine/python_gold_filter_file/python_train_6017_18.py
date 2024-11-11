N, M, V, P = map(int, input().split())
As = list(map(int, input().split()))

As.sort(reverse=True)

scoreP = As[P-1]

def isOK(k):
    if k < P or As[k] == scoreP:
        return True

    scoreK = As[k] + M
    if scoreK < scoreP:
        return False

    rest = M*(V-1)
    rest -= M*(P-1)
    if rest <= 0:
        return True

    for i in range(P-1, N):
        if i != k:
            rest -= min(M, scoreK-As[i])
    if rest <= 0:
        return True

    return False


ng, ok = N, -1
while abs(ok-ng) > 1:
    mid = (ng+ok) // 2
    if isOK(mid):
        ok = mid
    else:
        ng = mid

print(ok+1)
