# cattuper's solution
import sys
input = sys.stdin.buffer.readline
n, q = map(int, input().split())
c = list(map(int, input().split()))
l = [0] * q
r = [0] * q

queries = [[] for _ in range(n)]
rights = [[] for _ in range(n)]
for i in range(q):
    l[i], r[i] = map(int, input().split())
    l[i] -= 1
    queries[l[i]].append(i)

last_app = [-1] * (n+1)
for i in range(n):
    if last_app[c[i]] != -1:
        last = last_app[c[i]]
        rights[last].append(i)
    last_app[c[i]] = i



ans = [0] * q

seg = [0] * (1 << 20)

def add(x):
    x += 1 << 19
    while x:
        seg[x] += 1
        x = x // 2

def sum_of(l, r):
    l += 1 << 19
    r += 1 << 19
    ans = 0
    while l < r:
        if l % 2 == 1:
            ans += seg[l]
            l += 1
        if r % 2 == 1:
            ans += seg[r-1]
            r -= 1
        l //= 2
        r //= 2
    return ans

        
for i in range(n-1, -1, -1):
    for right in rights[i]:
        add(right)
    for q_ind in queries[i]:
        left = l[q_ind]
        right = r[q_ind]
        ans[q_ind] = (right - left) - sum_of(left, right)

for i in range(q):
    print(ans[i])