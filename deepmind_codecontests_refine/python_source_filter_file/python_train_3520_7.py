
def asum(l,r):
	global cumsum
	l+=1
	r+=1
	return cumsum[r-1]-cumsum[l-1]
def check(l,r):
	global dp
	if l==r:
		return 0
	if l == r-1:
		return arr[l]+arr[r]
	if dp[l][r] != None:
		return dp[l][r]
	else:
		ans = 10**9
		for i in range(l, r):
			st1 = asum(l,i)
			st2 = asum(i,r+1)
			ans = min(st1 + st2 + check(l,i)+ check(i+1, r), ans)
		
		dp[l][r] = ans
		return ans





ll = int(input())
arr = [int(i) for i in input().split()]
cumsum = [0]

for i in arr:
	cumsum.append(cumsum[-1]+i)
dp = [[None for i in range(ll+1)] for j in range(ll+1)]
print(check(0, ll-1))
