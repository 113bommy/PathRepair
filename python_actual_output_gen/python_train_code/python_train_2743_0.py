N, K = map(int, input().split())
A = list(map(int, input().split()))

def isOk(x):
    cnt = 0
    for a in A:
        cnt += a // x
    return cnt <= K

ok = max(A)
ng = 0
while ok - ng > 1:
    mid = (ok + ng) // 2
    if isOk(mid):
        ok = mid
    else:
        ng = mid

print(ok)
