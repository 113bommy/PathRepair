N=int(input())
X=list(map(int,input().split()))
A=sum(X)
y=N*((round(A/N)-A/N)**2)-(A**2)/N
B=sum([i**2 for i in X])
print(int(y+B))