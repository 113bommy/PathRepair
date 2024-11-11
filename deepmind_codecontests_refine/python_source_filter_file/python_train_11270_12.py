import sys, math
#map(int, sys.stdin.readline().split())
#list(map(int, sys.stdin.readline().split()))

t = int(sys.stdin.readline())

for _ in range(t):
	n = int(sys.stdin.readline())
	liste = list(map(int, sys.stdin.readline().split()))
	ans = "NON"
	out = [0, 0, 0]
	pp = [10001]*n
	pg = [10001]*n
	val = [0, 0, 0]
	for j in range(1, n):
		pp[j] = min(pp[j-1], liste[j-1])
	for j in range(n-2, -1, -1):
		pg[j] = min(pg[j+1], liste[j+1])
		if pg[j] < liste[j] and pp[j] < liste[j]:
			ans = "YES"
			val = [pp[j], liste[j], pg[j]]
	for i in range(n):
		if liste[i] == val[0]:
			out[0] = i+1
		if liste[i] == val[1]:
			out[1] = i+1
		if liste[i] == val[2]:
			out[2] = i+1
	print(ans)
	if ans == "YES":
		print(*out)
	#print(pp, pg)