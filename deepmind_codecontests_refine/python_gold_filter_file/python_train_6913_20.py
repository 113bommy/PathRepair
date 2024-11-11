def dSum(n):
	ans = 0
	while n>0:
		ans += n%10
		n = n//10
	return ans 
def solve(k,d,ans):
    if k>1 and d==0:
        return "No solution"
    else:
        for i in range(10):
            if dSum(dSum(dSum(dSum(int(ans + str(i)))))) == d:
                return int(ans + str(i))
        
k, d = list(map(int ,input().split(' ')))
ans = '1'*(k-1)
print(solve(k,d,ans))
