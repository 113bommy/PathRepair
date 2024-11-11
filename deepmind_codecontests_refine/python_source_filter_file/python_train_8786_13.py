
n = int(input())
l = list(map(int, input().split()))

x, y = map(int, input().split())
co = 0
for i in range(n):
	if sum(l[:i]) >= x and sum(l[:i]) <= y and sum(l[i:]) >= x and sum(l[i:]) <= y:
		co = 1
		break
if co == 1:
	print(l[i])
else:
	print(0)
