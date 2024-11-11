n,s = map(int, input().split())
go = list(map(int, input().split()))
come = list(map(int, input().split()))
if go[0] == 0:
	print('NO')
	exit()
if go[s-1] == 0 and come[s-1] == 0:
	print('NO')
	exit()
if go[s-1] == 1:
	print('YES')
	exit()

for i in range(s, n):
	if go[s] == 1 and come[s] == 1:
		print('YES')
		exit()
print('NO')