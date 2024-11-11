# import sys
# sys.stdin = open("#input.txt", "r")

n = int(input())

def solve():
	ls = list(map(int, input().split()))
	dec = []
	fin = False
	for i in range(n-1):
		if ls[i+1] < ls[i]:
			if dec and dec[-1] != i-1:
				return False,-1
			else:
				dec.append(i)
		else: fin = True
	if not dec:
		return True,1,1
	dec.append(dec[-1]+1)
	if dec[-1] + 1 < n and ls[dec[0]] > ls[dec[-1]+1] and dec[0] - 1 >= 0 and ls[dec[-1]] < ls[dec[0]-1]:
		return False,-1
	return True,dec[0]+1,dec[-1]+1

ans = solve()
if ans[0]:
	print("yes")
	print(ans[1],ans[2])
else:
	print("no")