MOD = 10 ** 9 + 7

n = int(input())
p = [0] + list(map(int, input().split()))

ways = [0 for i in range(n + 2)]


for i in range(1, n + 1):
    ways[i] = 1
    for j in range(p[i], i):
        ways[i] += ways[j] + 1
        ways[i] %= MOD

print(sum(ways) + n)
