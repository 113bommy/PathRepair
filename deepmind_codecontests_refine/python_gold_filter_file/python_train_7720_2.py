from sys import stdin
from itertools import tee

def input():
    return stdin.readline()

def remove_divisors(x, xs):
    return [y for y in xs if y%xs != 0]


q = int(input())
for _ in range(q):
    n = int(input())
    aas = list(set(map(int,input().split())))
    aas.sort(reverse=True)
    if len(aas) > 2 and aas[1]*2 > aas[0] and aas[2]*2 > aas[0]:
        print(sum(aas[0:3]))
        continue
    ulim2 = list(map(sum, zip(aas[:-1], aas[1:])))  + [0]
    ulim3 = list(map(sum, zip(aas[:-2], ulim2[1:]))) + [0,0]

    it1 = iter(zip(aas, ulim3, ulim2))

    answer = 0
    try:
        while True:
            a, u3, _ = next(it1)
            if u3 < answer:
                break
            it1, it2 = tee(it1)

            def f1(i):
                b, _, _ = i
                return a%b != 0

            it2 = filter(f1, it2)
            tsum = 0
            try:
                while True:
                    b, _, u2 = next(it2)
                    if u2 < tsum:
                        break
                    it2, it3 = tee(it2)

                    def f2(i):
                        c, _, _ = i
                        return b%c != 0

                    it3 = filter (f2 , it3)
                    c,_,_ = next(it3, (0,0,0))
                    tsum = max(tsum, b+c)
            except StopIteration:
                pass
            answer = max(answer, a + tsum)
    except StopIteration:
        pass
    print(answer)
