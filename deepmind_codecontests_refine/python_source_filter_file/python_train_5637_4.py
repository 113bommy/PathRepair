n = int(input())
a = list(map(int, input().split()))

l = [0]*200000

for i in range(n):
	for j in range(i+1, n-1):
		l[a[i]+a[j]] += 1

print(max(l))