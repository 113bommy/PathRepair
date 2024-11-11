N=int(input())
X=list(map(int, input().split()))
sum=sum(X)
ave=int(sum/N)+1
Y=0
for i in X:
	Y+=(i-ave)**2
print(Y)