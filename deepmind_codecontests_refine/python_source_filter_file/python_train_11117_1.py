
N,M = map(int,input().split())

AC = 0
WA = 0


was = [0]*(N+1)
acs = [0]*(N+1)

for i in range(M):
	p,s = input().split()
	p = int(p)

	if s = "AC":
		if acs[p] == 0:
			AC += 1
			WA += was[p]
			acs[p] = 1
	else:
		was[p] += 1

print(AC,WA)