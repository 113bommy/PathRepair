'''input
2
0 0
'''
n = int(input())
a = list(map(int, input().split()))
f1 = [0, -1, 1]
for i in range(n):
	f = 1
	for j in range(n):
		a[j] = (a[j] + f) % n
		f = f1[f]
	if a == list(range(1, n+1)):
		print("Yes")
		break
else:
	print("No")