X, Y = list(map(int, input().split()))

if X % Y == 0:
    ans = -1
else:
    ans = X

print(ans)