'''input
2
2 1
'''
n = int(input())
a = sorted(map(int, input().split()))
b = list(range(1, n+1))
t = 0
for x in range(n):
	if a[x] > b[x] + t:
		a[x] = b[x] + t
	elif a[x] < b[x]:
		t -= 1
print(max(a) + 1)




