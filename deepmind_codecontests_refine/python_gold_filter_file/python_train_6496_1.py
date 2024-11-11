# http://codeforces.com/problemset/problem/339/B
n, m = [int(x) for x in input().split()]
q = [int(x) for x in input().split()]
ans = 0
temp = 1
for x in q:
	ans += ( (x+n-temp)%n )
	temp = x
	
print(ans)
	