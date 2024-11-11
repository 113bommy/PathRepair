n = int(input())
val = list(map(int, input().split()))

ans = [0] * n
ans[0] = 1 if n % 2 == 0 else 2

for i in range(1, n):
    if val[i] % 2 == 1:
        ans[i] = ans[i - 1]
    else:
        ans[i] = ans[i - 1] % 2 + 1

print("\n".join(map(str, ans)))