r,c,k  = [int(tmp) for tmp in input().split()]
ans = 0
for i in range(1, k+1) :
	r = r - (4*(i-1))
	c = c - (4*(i-1))
	ans = ans + 2*r + 2*c - 4
print(ans)