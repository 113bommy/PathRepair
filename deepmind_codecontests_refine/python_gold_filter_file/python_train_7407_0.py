import sys;readline = sys.stdin.buffer.readline
def i1(): return int(readline())
def nl(): return [int(s) for s in readline().split()]
def nn(n): return [int(readline()) for i in range(n)]
def nlp(x): return [int(s)+x for s in readline().split()]
def nll(n): return [[int(s) for s in readline().split()] for i in range(n)]
def mll(n): return ([int(s) for s in readline().split()] for i in range(n))
def s1(): return readline().rstrip()
def sn(n): return [readline().rstrip() for i in range(n)]
def sm(n): return (readline().rstrip() for i in range(n))
def redir(s): global readline;import os;fn=sys.argv[0] + f'/../in-{s}.txt';readline = open(fn).readline if os.path.exists(fn) else readline

redir('a')
n = i1()
parents = [int(s)-1 for s in sm(n)]
# ip = sorted(enumerate(parents), key=lambda x:x[1])
# print(n,parents)
ulevel = [-1]*n
for i in range(n):
# for i,p in ip:
    # dfs(i)
    # global ulevel, parents, n
    # if i == 3:
    #     import pdb; pdb.set_trace()
    if ulevel[i] > 0: continue
    cnt = 1
    p = parents[i]
    while p >= 0 and ulevel[p] < 0:
        cnt += 1
        ulevel[p] = i
        i = p
        p = parents[i]
    if p < 0:
        x = 1
    else:
        x = ulevel[p] + 1
    for _ in range(cnt):
        p = ulevel[i]
        ulevel[i] = x
        x += 1
        i = p
    # case 1, u[i] < 0 p[i]
# print(n,parents)
# print(ulevel)
print(max(ulevel))
