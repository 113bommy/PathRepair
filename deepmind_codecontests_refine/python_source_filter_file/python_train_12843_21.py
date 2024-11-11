n, k = map(int, input().split())
a = list(map(str, input().split()))
sum = 0
for i in a:
	if a.count('4')+a.count('7') <= k:
		sum += 1
print(sum)