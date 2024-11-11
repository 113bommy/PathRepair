n, m = map(int, input().split())
inputList = [0] + list(map(int, input().split())) + [0]
inputIntervals = []
for _ in range(m):
    inputIntervals.append(tuple(map(int, input().split())))


def wynik(in1, in2):
    intervals = [[] for _ in range(n + 1)]
    for (nr, (a, b)) in enumerate(in2):
        intervals[b] += [(a, nr + 1)]
    wyn = (0, [])
    minek = in1[1]
    numerki = []
    for i in range(2, n + 1):
        minek = min(minek, in1[i - 1])
        for (j, ind) in intervals[i - 1]:
            for k in range(j, i):
                in1[k] -= 1
                minek = min(minek, in1[k])
            numerki += [ind]
        wyn = max(wyn, (in1[i] - minek, numerki))
    return wyn


odp = max(wynik(list(reversed(inputList)),
          list(map(lambda x: (n - x[1] + 1, n - x[0] + 1), inputIntervals))),
          wynik(inputList, inputIntervals))
print(odp[0], len(odp[1]), sep='\n')
print(*odp[1])
