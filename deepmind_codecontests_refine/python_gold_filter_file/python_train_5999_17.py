k = int(input())
r = map( int, input().split() )
i0 = 0
ans = k - 25
for i in sorted(r):
	ans += i - i0 - 1
	i0 = i
print(max(0, ans))