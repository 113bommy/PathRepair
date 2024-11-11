from sys import stdin
input = stdin.readline
from types import GeneratorType
def bootstrap(f, stack=[]):
    def wrappedfunc(*args, **kwargs):
        if stack:
            return f(*args, **kwargs)
        else:
            to = f(*args, **kwargs)
            while True:
                if type(to) is GeneratorType:
                    stack.append(to)
                    to = next(to)
                else:
                    stack.pop()
                    if not stack:
                        break
                    to = stack[-1].send(to)
            return to
    return wrappedfunc
dupa = None
nbr = None

@bootstrap
def dfs(v):
	dupa[v] = 1
	for w in nbr[v]:
		if dupa[w] == -1:
			chuj = yield dfs(w)
			dupa[v] += chuj
	yield dupa[v]
q = int(input())
for _ in range(q):
	n = int(input())
	nbr = [[] for i in range(n)]
	for i in range(n-1):
		a,b = map(int,input().split())
		nbr[a-1].append(b-1)
		nbr[b-1].append(a-1)
	pier = int(input())
	p = list(map(int,input().split()))
	p.sort()
	p.reverse()
	dupa = [-1] * n
	dfs(0)
	actual = [dupa[i]*(n-dupa[i]) for i in range(1,n)]
	actual.sort()
	actual.reverse()
	if pier < n:
		p += [1]*(n-1-pier)
	else:
		p.reverse()
		while len(p) > n:
			ddd = p.pop(-1)
			p[-1] = (p[-1]*ddd)%(10**9+7)
		p.reverse()
	wyn = 0
	for i in range(n-1):
		wyn += actual[i]*p[i]
	print(wyn%(10**9+7))