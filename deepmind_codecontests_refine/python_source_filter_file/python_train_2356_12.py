#n = int(input())
#a = list(map(int, input().split()))

n = 4
a = [1, 5, 2, 5]

cnt = 0
for i in range(1, n-1):
	if a[i] < a[i-1] and a[i] < a[i+1]:
		cnt += 1
	elif a[i] > a[i-1] and a[i] > a[i+1]:
		cnt += 1

print(cnt)
