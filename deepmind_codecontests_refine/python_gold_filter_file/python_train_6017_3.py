

N,M,V,P = map(int, input().split())

A = list(map(int, input().split()))


A.sort(reverse=True)
ok = P-1
ng = N 
while abs(ok - ng) > 1:
    mid = (ok + ng) // 2
    curr_max = A[mid] + M

    if curr_max < A[P-1]:
        ng = mid
        continue

    cnt = 0
    # midと上位P-1位に＋Mした分
    cnt += M + (P-1) * M
    for i in range(P-1, N):
        if i == mid: continue

        cnt += min(M, max(0, curr_max - A[i]))

    if cnt >= M*V:
        ok = mid
    else:
        ng = mid

print(ok + 1)