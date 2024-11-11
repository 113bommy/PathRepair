from collections import defaultdict, Counter
import sys

# dp[n][使った数字(bit)][合計] = count
dp = [defaultdict(Counter) for _ in [0]*11]
dp[0][0][0] = 0

for i in range(1, 11):
    for used, counter in dp[i-1].items():
        for j in filter(lambda x: used & 2**x == 0, range(10)):
            for total, count in counter.items():
                dp[i][used|2**j][total+j*i] += 1

for n, s in (map(int, l.rstrip().split()) for l in sys.stdin):
    print(sum(v for counter in dp[n].values() for k, v in counter.items() if k == s))
