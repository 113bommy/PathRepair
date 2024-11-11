import sys
import math
import bisect

def query_value(m, dist, population, r):
    n = len(dist)
    ans = m
    for i in range(n):
        if r >= dist[i] - 10 ** -8:
            ans += population[i]
    #print('m: %d, dist: %s, population: %s, r; %f, ans: %d' % (m, str(dist), str(population), r, ans))
    return ans

def solve(m, dist, population):
    n = len(dist)
    left = 0
    right = 10 ** 18
    if query_value(m, dist, population, right) < 10 ** 6:
        return -1
    cnt = 128
    while cnt:
        cnt -= 1
        mid = (left + right) / 2
        if query_value(m, dist, population, mid) >= 10 ** 6:
            right = mid
        else:
            left = mid
    return right

def main():
    n, m = map(int, input().split())
    dist = []
    population = []
    for i in range(n):
        x, y, a = map(int, input().split())
        dist.append(math.sqrt(x ** 2 + y ** 2))
        population.append(a)
    print(solve(m, dist, population))

if __name__ == "__main__":
    main()
