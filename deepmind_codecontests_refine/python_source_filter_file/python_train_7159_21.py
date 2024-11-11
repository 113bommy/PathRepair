import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

N, Q = map(int, input().split())
C = list(map(int, input().split()))

by_R = [[] for _ in range(N+2)]
for i in range(Q):
	l, r = map(lambda s: int(s)-1, input().split())
	by_R[r+1].append((l, i))

s = [0] * N
def update(pos, dif):
	while pos < N:
		s[pos] += dif
		pos |= pos + 1

def query(pos):
	res = 0
	while pos > 0:
		res += s[pos-1]
		pos &= pos - 1
	return res

diff = 0
ans = [-1] * Q
last = [-1] * N

for i, v in enumerate(C):
	if last[v] != -1:
		update(last[v], -1)
	else:
		diff += 1

	update(i, 1)
	last[v] = i

	for l, j in by_R[i+1]:
		ans[j] = diff - query(l)

print('\n'.join(map(str, ans)))
