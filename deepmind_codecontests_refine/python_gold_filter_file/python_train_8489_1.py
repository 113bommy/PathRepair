n,k,t = map(int,input().split())
co = n*t//100
rem = k*(n*t%100)//100
sol = [k] * co
if n-len(sol) > 0:
	sol += [rem]
if n-len(sol) > 0:
	sol += [0] * (n-len(sol))
print(*sol)