inp = [int(input())]

def fnc(n):
	if n >= 3:
		half = (n-2)/2
		flr  = (n-2)//2

		if   half == flr: return(flr)
		else: return(flr+1)
	else:
		return(0)

for i in range(len(inp)): print(fnc(int(input())))