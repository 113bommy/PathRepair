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

    print("{}".format("uniform" if max(V) < 1.8*(S**0.5) else "poisson"))