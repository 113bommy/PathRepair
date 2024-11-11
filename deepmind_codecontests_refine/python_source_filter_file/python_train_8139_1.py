import sys
import collections
import heapq
import math
 
input = sys.stdin.readline
 
def rints(): return map(int, input().strip().split())
def rstr(): return input().strip()
def rint(): return int(input().strip())
def rintas(): return [int(i) for i in input().strip().split()]
    
def gcd(a, b):       
    if (b == 0): 
         return a 
    return gcd(b, a%b) 

n, m = rints()
graphs = collections.defaultdict(list)
nums = set()
for _ in range(m):
    u, v = rints()
    graphs[u].append(v)
    graphs[v].append(u)
    nums.add(u)
    nums.add(v)

times = list()
seen = set()
for i in nums:
    if i in seen: continue
    mn, mx = i, i    
    queue = []
    queue.append(i)
    while queue:
        cur = queue.pop()
        if cur in seen: continue
        seen.add(cur)
        mn = min(mn, cur)
        mx = max(mx, cur)

        for k in graphs[cur]:
            queue.append(k)
    times.append([mn, mx])

times.sort()
u, v = times[0]
ans = 0
merges = list()
# print(times)
for i in range(1, len(times)):
    i, j = times[i]
    if i <= v:
        ans += 1
        v = j
    else:
        merges.append([u,v])
        u, v = i, j

merges.append([u,v])
# print(merges)
for u, v in merges:
    for x in range(u, v+1):
        if x not in seen:
            ans += 1
print(ans)