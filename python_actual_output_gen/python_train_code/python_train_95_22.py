X = list(map(int, input().split()))
Count, Pages = 1, X[1]
while Pages < X[0]:
    Pages, Count = Pages + min(X[2], (X[1] + (Count * X[3]) - X[4])), Count + 1
print(Count)
