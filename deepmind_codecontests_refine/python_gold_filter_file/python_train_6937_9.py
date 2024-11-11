n, pos, l, r = map(int, input().split())
ans = 0
if l == 1 and r == n:
	ans = 0
elif l == 1:
	ans = abs(pos-r)+1
elif r == n:
	ans = abs(pos-l)+1
else:
	ans = abs(pos-l)+1+abs(r-l)+1
	ans = min(ans, abs(pos-r)+1+abs(r-l)+1)
print(ans)