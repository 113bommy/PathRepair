n, x, y = map(int, input().split())

S = input()

F = ['0'] + (['0'] * x)
F[len(F) - y - 1] = '1'
ans = 0
for i in range(len(F)):
    if S[len(S) - 1 - i] != F[len(F) - 1 - i]:
        ans += 1

print(ans)
    