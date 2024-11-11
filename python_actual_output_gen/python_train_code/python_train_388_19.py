n = int(input())
l = list(map(int, input().split()))

minimum = min(l)
maximum = max(l)
indexMax = 0
indexMin = 0


for i in range(0, len(l)):
	if l[i] == maximum:
		indexMax = i
	if l[i] == minimum:
		indexMin = i

count = 0

if indexMin == 0 or indexMax == 0 or indexMin == n-1 or indexMax == n-1:
	count = n - 1
elif indexMin < indexMax and indexMin < n - indexMax:
	count = n - 1 - indexMin
elif indexMin < indexMax and indexMin > n - indexMax:
	count = indexMax
elif indexMax < indexMin and indexMax < n - indexMin:
	count = n - 1 - indexMax
elif indexMax < indexMin and indexMax > n - indexMin:
	count = indexMin


print(count)