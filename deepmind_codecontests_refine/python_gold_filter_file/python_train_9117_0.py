def sampleVariance(V):
    X = sum(V) / len(V)
    S = 0.0
    for x in V:
        S += (X-x)**2

    S /= (len(V)-1)
    return (X, S)

#That awkward moment when you realized that variance is sigma^2 but you just took the stat course this semester
for i in range(int(input())):
    V = list(map(int, input().split()))
    X, S = sampleVariance(V)
    v1 = X
    v2 = (2*X) ** 2 / 12

    if abs(v1-S) < abs(v2-S):
        print(int(X))
    else:
        print((max(V)+min(V)) // 2)