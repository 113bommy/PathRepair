N = int(input())
V = list(map(int, input().split()))
C = list(map(int, input().split()))
total = sum(V)
C.sort()
if C[-1] + C[-2] > total:
	print("YES")
else:
	print("NO")