N = int(input())
a = [int(input()) for _ in range(N)]

ans, nex = 1, a[0]
while ans < N or nex == 2:
	 nex = a[nex - 1]
	 ans += 1
	 
print(ans if ans != N else -1)