l1, r1, l2, r2, k = list(map(int,input().split()))
l = max(l1, l2)
r = max(r1, r2)
ans = r-l+1
if k >= l and k <= r :
	ans = ans -1
ans = max(ans, 0)
print(ans) 