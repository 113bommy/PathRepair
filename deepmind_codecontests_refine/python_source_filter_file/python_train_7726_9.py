import math
import collections
t = int(input())
for _ in range(t):
    N, m = map(int, input().split())
    a = list(map(int, input().split()))
    a2 = [int(math.log(a[i], 2)) for i in range(m)]
    if sum(a) < N:
        print(-1)
    else:
        a2.sort()
        table = collections.defaultdict(int)
        for x in a2:
            table[x] += 1
        ans = 0
        for i, x in enumerate((bin(N)[2:])[::-1]):
            if x == "1":
                if table[i] > 0:
                    table[i] -= 1
                else:
                    id = i
                    while(table[id] == 0):
                        id += 1
                    table[id] -= 1
                    for j in range(id, i-1, -1):
                        table[j] += 1
                    ans += id - i
            if table[i] >= 2:
                table[i+1] += table[i]//2
                table[i] %= 2
        print(ans)
