L=lambda:list(map(int,input().split()))
n,t=L()
x=sorted(L()for _ in'0'*n)
num=0
for i in range(n-1):
	ans=x[i][0]+t+(x[i][1]+x[i+1][1])/2;r=x[i+1][0]
	if ans==r:num+=2
	if ans<r:num+=2
print(num+2)
