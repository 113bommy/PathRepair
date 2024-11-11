def gcd(a,b):
	if a<=1:
		return b
	elif b<=1:
		return a

	if a>=b:
		return gcd(a%b,b)
	else:
		return gcd(a,b%a)
# import math
n=int(input())
arr = list(map(int,input().split()))

gcdList = [1]*(n)
gcdList[-1] = arr[-1] 

for i in range(n-2,-1,-1):
	gcdList[i]=gcd(arr[i],gcdList[i+1])

# print(gcdList)
ans = [0]*(n-1)

for i in range(n-1):
	ans[i]=arr[i]*gcdList[i+1]//gcdList[i]

# print(*ans)
solution = ans[0]
for i in range(1,n-1,1):
	solution = gcd(solution,ans[i])
print(solution)
