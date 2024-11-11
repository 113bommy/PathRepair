N = int(input())
A = [int(input()) for _ in range(N)]

if A[0] != 0:
    print(-1)
    exit()
ans = A[-1]
now = A[-1] + 1

for a in A[::-1]:
    now -= 1
    if a > now:
        ans += a
        now = a
    elif a < now:
        ans = -1
        break

print(ans)