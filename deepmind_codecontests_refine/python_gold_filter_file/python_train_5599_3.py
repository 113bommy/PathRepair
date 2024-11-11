memo=dict()
t=int(input())
def f(x):
	if x in memo:
		return memo[x]
	if x<=1:
		return D*x
	ret=D*x

	if x%2==0:
		ret=min(ret,f(x//2)+A)
	else:
		ret=min(ret,f(x//2)+A+D,f(x//2+1)+A+D)
	
	if x%3==0:
		ret=min(ret,f(x//3)+B)
	elif x%3==1:
		ret=min(ret,f(x//3)+B+D)
	else:
		ret=min(ret,f(x//3+1)+B+D)

	if x%5<=2:
		ret=min(ret,f(x//5)+C+D*(x%5))
	else:
		ret=min(ret,f(x//5+1)+C+D*(5-x%5))
	memo[x]=ret
	return ret
for _ in range(t):
	memo=dict()
	n,A,B,C,D=map(int,input().split())
	print(f(n))

