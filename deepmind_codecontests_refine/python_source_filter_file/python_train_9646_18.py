#Bhargey Mehta (Junior)
#DA-IICT, Gandhinagar
import sys, math, queue
#sys.stdin = open('input.txt', 'r')
MOD = 998244353
sys.setrecursionlimit(1000000)

def ok(n, x):
    global sq
    a = []
    for i in range(len(n)):
        if x&1:
            a.append(n[i])
        x = x>>1
    a = ''.join(a)
    if a in sq: return len(n)-len(a)
    return -1

i = 1
sq = set()
while i*i <= 10**9:
    sq.add(str(i*i))
    i += 1
n = input()

ans = None
for i in range(1<<len(n)):
    t = ok(n, i)
    if t == -1: continue
    if ans is None: ans = t
    else: ans = min(ans, t)
if ans is None: ans = -1
print(ans)