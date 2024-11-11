#750A in codeforces
n,k = map(int,input().split())
remain = 240 - k
solve = 0
flag = 0
for i in range(n,-1,-1):
	solve = 5*((i*(i+1))//2)
	if solve <= remain:
		print(i)
		break