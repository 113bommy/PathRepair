def calc(X, Y):
    if len(Y) == 3: return sum(Y)
    for x in X:
        for y in Y:
            if y % x == 0: break
        else:
            return calc([i for i in X if i != x], sorted(Y+[x])[::-1])
    return sum(Y)
for _ in range(int(input())):
    N = int(input())
    A = sorted(set([int(a) for a in input().split()]))[::-1]
    print(max(calc(A, []), calc(A[1:], [])))
