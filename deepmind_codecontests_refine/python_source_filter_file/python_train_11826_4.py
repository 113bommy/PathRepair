n = int(input())

l = list(map(int, input().split()))

l.sort()

mind = 10**9

for i in range(n-1):
	mind = min(mind, l[i+1] - l[i])

count = 0

for i in range(n-1):
	if l[i+1] - l[i] == mind:
		count+=1

print(mind, count)