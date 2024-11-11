X, Y = list(map(int, input().split()))
if X % Y == 0:
    re = -1
elif X < Y:
    re = X
else:
    re = X * Y - X
print(re)