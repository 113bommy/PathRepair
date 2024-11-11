N = int(input())
list_of_a = list(map(int, input().split()))

ng = max(0, sum(list_of_a)-(N-1)*N) - 1
ok = max(0, (max(list_of_a) - (N-1)) * N)
while ok - ng > 1:
    mid = (ok + ng) // 2
    count = 0
    for a in list_of_a:
        count += (a + mid + 1) // (N+1)
    if count <= mid:
        ok = mid
    else:
        ng = mid

#'ok'-i (i=1..N) may be better

for i in range(0, 30 * N + 1):
    mid = ok - i
    if mid < 0:
        break
    count = 0
    for a in list_of_a:
        count += (a + mid + 1) // (N+1)
    if count == mid:
        ans = mid

print(ans)
