N, K = map(int,input().split())
A = list(map(int, input().split()))

OK = 10**9
NG = 0

while OK - NG > 1:
    ans = 0
    mid = (OK+NG)//2
    for a in A:
        ans += (a-0.1)//mid
    if ans > K:
        NG = mid
    else:
        OK = mid
print(OK)