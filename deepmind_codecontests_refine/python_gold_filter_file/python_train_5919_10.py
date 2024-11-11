N = int(input())
A = list(map(int, input().split()))

Ad = [A[i] - A[i+1] for i in range(N-1)]

ans = 1
p = 0
for d in Ad:
    if d * p < 0:
        ans += 1
        p = 0
    elif d != 0:
        p = d

print(ans)