import math, collections

for _ in range(int(input())):
    n = int(input())
    seen = collections.defaultdict(bool)
    ans = []
    for i in range(4 * n, 0, -2):
        if not seen[i]:
            ans.append(i)
            for j in range(2, int(math.sqrt(i)) + 1):
                if not i % j:
                    seen[j] = True
                    seen[i // j] = True
        if len(ans) == n:
            break
    print(*ans)
    