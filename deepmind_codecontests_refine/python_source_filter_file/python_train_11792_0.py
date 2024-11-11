from sys import stdin, gettrace

if gettrace():
    inputi = input
else:
    def input():
        return next(stdin)[:-1]


    def inputi():
        return stdin.buffer.readline()


def solve():
    n,k = map(int, inputi().split())
    l1, r1 = map(int, inputi().split())
    l2, r2 = map(int, inputi().split())
    overlap = min(r1, r2) - max(l1, l2)
    if overlap * n >= k:
        print(0)
        return
    maxoverlap = max(r1,r2) - min(l1,l2)
    if overlap >= 0:
        if maxoverlap * n >= k:
            k -= overlap*n
            print(k)
        else:
            k -= maxoverlap
            print((maxoverlap - overlap)*n + k*2)
    else:
        cost = 0
        for i in range(n):
            noverlap = min(maxoverlap, k)
            cost += -overlap + noverlap
            k -= noverlap
            if k <= -overlap:
                cost += k*2
                break
        else:
            cost += k*2
        print(cost)




def main():
    t = int(inputi())
    for _ in range(t):
        solve()


if __name__ == "__main__":
    main()