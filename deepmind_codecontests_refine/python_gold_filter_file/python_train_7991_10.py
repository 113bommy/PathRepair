N, K = map(int, input().split())
A = list(map(int, input().split()))

ng = 0
ok = max(A)

while ok - ng > 1:
    cnt = 0
    l = (ok + ng) // 2
    for a in A:
        cnt += (a // l) + (a % l != 0) - 1

    if cnt <= K:
        ok = l
    else:
        ng = l
print(ok)