inp = [*open(0)]
for t in range(int(inp[0])):
	t *= 3
	N = int(inp[t+1])
	if N == 1: print(max(int(inp[t+2]), int(inp[t+3]))); continue
	
	a = list(map(int, inp[t+2].split()))
	b = list(map(int, inp[t+3].split()))
	c = sorted(list(zip(a, b)))
	
	P, M = 0, 0
	for i in range(N - 1, -1, -1):
		if P + c[i][1] < c[i][0]:
			P += c[i][1]
		else: M = c[i][0]; break
	
	print(max(P, M))

# Code to spam (1, 1e9, 1e9) 2e5 times.
# N=2*10**5
# print(N)
# [print("1\n1000000000\n1000000000")for i in range(N)]