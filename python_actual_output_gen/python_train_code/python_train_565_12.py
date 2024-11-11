t = int(input())
ans = [0] * t
for req in range(t):
    x, y, n = map(int, input().split())
    ans[req] = (n // x) * x + y
    if ans[req] > n:
        ans[req] -= y
for i in ans:
    print(i)

