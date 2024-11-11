from collections import defaultdict, Counter

n = int(input())
a = list(int(v) for v in input().split()) + [-1000000002]
c = Counter(a)
#print(a, set(a), sorted(set(a)))
top, sec = sorted(set(a))[-1:-3:-1]
topC, secC = [0]*n, [0]*n
#print(top, c[top], sec, c[sec])
for i in range(n-1):
    u, v = (int(v) for v in input().split())
    if a[u-1] == top: topC[v-1] += 1
    if a[v-1] == top: topC[u-1] += 1
    if a[u-1] == sec: secC[v-1] += 1
    if a[v-1] == sec: secC[u-1] += 1

ans = top+2 # worst case
for i in range(n):
    # Process top numbers
    add = 1 if a[i] == top else 0 # haista vittu
    if topC[i]+add < c[top]: continue # there are tops beyond connected
    best = top+1 if topC[i] else top # sole top or tops connected
    # Second top can be nexus only if all tops are connected to it

    # Process second numbers
    add = 1 if a[i] == sec else 0 # haista vittu
    if secC[i]+add < c[sec]: best = max(best, sec+2) # seconds beyond
    # sec+1 <= top so we're done

    ans = min(ans, best)

print(ans)
