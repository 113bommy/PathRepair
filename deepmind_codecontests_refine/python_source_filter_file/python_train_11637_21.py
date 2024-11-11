import bisect
n = int(input())
A = tuple(map(int, input().split()))
B = tuple(map(int, input().split()))
sA = set(A)
sB = set(B)
x = 0
for i in sA & sB:
    r = bisect.bisect_right(A, i)
    l = bisect.bisect_left(B, i)
    x = max(x, r-l)
ans = B[x:] + B[:-x]
for a, b in zip(A, ans):
    if a == b:
        print("No")
        break
else:
    print("Yes")
    print(*ans)