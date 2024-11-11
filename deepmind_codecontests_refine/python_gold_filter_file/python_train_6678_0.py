n = int(input())
l = list(map(int,input().split()))
times = [0] * 200001
for i in l:
	times[i] += 1
maks = 0
k = 0
for i in range(200001):
	if times[i] > maks:
		k = i
		maks = times[i]
#mamy najczesciej wystepujacy
start = 0
for i in range(200001):
	if l[i] == k:
		start = i
		break

wyn = n - maks
print(wyn)
for i in range(start + 1, n):
	if l[i - 1] != l[i]:
		print((l[i] > l[i - 1]) + 1, end = " ")
		print(i + 1, end = " ")
		print(i)
		l[i] = l[i - 1]
i = start
while i > 0:
	if l[i - 1] != l[i]:
		print((l[i - 1] > l[i]) + 1, end = " ")
		print(i, end = " ")
		print(i + 1)
		l[i - 1] = l[i]
	i -= 1