N, X = int(input()), list(map(int, input().split()))
if len(list(filter(lambda x: x % 2 == 1, X))) not in [0, X[0]]:print(*sorted(X))
else:print(*X)

# Come together for getting better !!!!
