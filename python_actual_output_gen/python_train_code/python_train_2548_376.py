n = int(input())

X = list(map(int, input().split()))
X.sort()
print(sum(X[n:2*n]))
