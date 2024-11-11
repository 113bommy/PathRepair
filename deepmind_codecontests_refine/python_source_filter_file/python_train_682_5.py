n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

numa = [0] * 5
numb = [0] * 5
for i in a:
	numa[i-1] += 1
for i in b:
	numb[i-1] += 1
failed = False
for i in range(0, 5):
	if (numa[i] + numb[i] % 2 == 1):
		failed = True
		break
steps = 0
if (failed):
	print(-1)

else:
	for i in range(0, 5):
		steps += abs(numa[i] - numb[i])/2
	print (int(steps/2))