import time


def solution(cost, start_ind):
    ans = 0
    cur = cost[-1]
    for i in range(len(cost) - 2, -1, -1):
        if cost[i] < cur:
            cur = cost[i]
        else:
            ans += 1
    return ans


def main():
    n = int(input())
    cost = list(map(int, input().split()))
    print(solution(cost, 0))


t = int(input())
for i in range(t):
    main()