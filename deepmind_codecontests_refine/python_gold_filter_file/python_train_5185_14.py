import math
N,D = map(int,input().split())
X = [list(map(float, input().split())) for i in range(N)]
counter = 0
for i, x0 in enumerate(X): 
    for x1 in X[i+1:]:
        if math.sqrt(sum([(a-b)**2 for a, b in zip(x0,x1)])).is_integer():
            counter+=1
print(counter)
