N = int(input())
ABs = [tuple(map(int, input().split())) for _ in range(N)]

ans = 0
minB = 10**9
isSame = True
for A, B in ABs:
    ans += A
    if A > B:
        minB = min(minB, B)
    if A != B:
        isSame = False

if isSame:
    print(0)
else:
    print(ans-minB)
