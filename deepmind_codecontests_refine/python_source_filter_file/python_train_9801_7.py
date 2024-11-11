def solve():
	_ = int(input())
	a = list(map(int, input().split()))
	a.sort()
	_ = int(input())
	qq = list(map(int, input().split()))
	res = sum(a)
	for q in qq:
		 print(res - a[q])

solve()
