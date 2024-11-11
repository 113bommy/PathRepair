k,d = map(int,input().split())
if d == 0 and k == 1:
	print(0)
	exit()
r = d//k
if r > 9 or d == 0 and k > 1:
	print("No solution")
	exit()
r1 = d%k
s = ""
while r1:
	r1 = r1 - 1
	s = s + str(r+1)
s = s + (k-len(s))*str(r)
print(s)