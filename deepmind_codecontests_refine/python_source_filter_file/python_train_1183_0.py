X = list(map(int, input().split()))
Squares = sorted(list(map(int, input().split())))
if X[1] >= len(Squares):
    print(-1)
    exit()
print(Squares[-X[1]], Squares[-X[1]])
