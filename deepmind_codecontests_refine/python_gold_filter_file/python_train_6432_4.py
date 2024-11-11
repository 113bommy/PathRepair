N=int(input())
X=list(map(int, input().split()))
sum=sum(X)
ave=round(sum/N)
Y=0
for i in X:
	Y+=(i-ave)**2
print(Y)