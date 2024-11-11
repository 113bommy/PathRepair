import sys
input = sys.stdin.readline
for _ in range(int(input())):
	y,x = map(int, input().split())
	*li, = map(int, input().split())
	ans =x
	li1 = []
	for i in range(y):
		if x//2 <= li[i] <= x:
			print(1)
			print(i+1)
			break
		if li[i] <= ans:
			li1 += [i+1]
			ans -= li[i]

		if ans <= x/2:
			print(len(li1))
			print(*li1)
			break
	else:
		print(-1)
	

	