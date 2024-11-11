N,M = map(int,input().split())
X = list(map(int,input().split()))
li = [0]*(M-1)
X.sort()
for i in range(M-1):
    li[i] = abs(X[i+1]-X[i])
li.sort()
print(sum(li[:max(0,M-N)]))