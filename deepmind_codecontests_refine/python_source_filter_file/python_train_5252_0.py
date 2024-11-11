from collections import defaultdict, deque
from heapq import heappush, heappop
from math import inf

ri = lambda : map(int, input().split())

def sm(x):
    ans = 0
    while x:
        ans += (x % 10)
        x //= 10
    return ans

def solve():
    n = int(input())
    A = list(ri())
    ans = 0
    cnt = defaultdict(int)
    for x in A:
        d = sm(x)
        if d % 3 == 0:
            if cnt[0] > 1:
                cnt[0] -= 1
                ans += 1
            else:
                cnt[0] += 1
        elif cnt[3-(d%3)] > 1:
            cnt[3-(d%3)] -= 1
            ans += 1
        else:
            cnt[d%3] += 1
    print(ans)


t = 1
#t = int(input())
while t:
    t -= 1
    solve()

