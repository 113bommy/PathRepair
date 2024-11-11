t = int(input())
for _ in range(t):
	a = sorted(int(v) for v in input().split())
	print("No" if a[0] + a[1] < a[2] else "Yes")