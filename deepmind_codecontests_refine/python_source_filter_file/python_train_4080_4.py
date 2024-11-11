import sys

def answer(n, k, a):
    mxa = max(a)
    costs = [[] for _ in range(mxa + 1)]
    for i in range(n):
        temp = a[i]
        cost = 0
        while temp > 0:
            costs[temp].append(cost)
            temp //= 2
            cost += 1
    best = 10**6
    for i in range(1, mxa+1):
        if len(costs[i]) >= k:
            costs[i].sort()
            best = min(best, sum(costs[i][:k]))

    return best
    

def main():
    n, k = map(int, sys.stdin.readline().split())
    a = list(map(int, sys.stdin.readline().split()))
    print(answer(n, k, a))
    return
main()