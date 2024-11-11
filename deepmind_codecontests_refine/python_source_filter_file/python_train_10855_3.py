from sys import stdin, stdout
input = stdin.buffer.readline

for _ in range(int(input())):
	n = int(input())
	*a, = map(int, input().split())
	if sum(a) % n:
		print(-1)
		continue
	k = sum(a) // n
	ans = []
	for i in range(1, n):
		if a[i] % (i + 1):
			ans.append([1, i + 1, i + 1 - a[i] % (i + 1)])
		ans.append([i + 1, 1, a[i] // (i + 1)])
	#print(a)
	for i in range(1, n):
		ans.append([1, i + 1, k])
	print(len(ans))
	for i in ans:
		print(*i)
		
	
			
