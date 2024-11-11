X, Y = list(map(int, input().split()))
if Y == X or Y == 1:
    re = -1
elif X < Y:
    re = X
else:
    re = X * Y - X
print(re)