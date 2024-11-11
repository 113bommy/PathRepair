N,K = list(map(int,input().split()))

X = []
Y = []
Z = []
for i in range(N):
    x,y = list(map(int,input().split()))
    X.append(x)
    Y.append(y)
    Z.append([x,y])

X.sort()
Y.sort()

min_rec=0

for i in range(N-1):
    for j in range(i+1,N):
        for k in range(N-1):
            for l in range(k+1,N):
                count=0
                for n in range(N):
                    if Z[n][0]>=X[i] and Z[n][0]<=X[j] and Z[n][1]>=Y[k] and Z[n][1]<=Y[l]:
                        count+=1
                if count==K:
                    min_rec = min(min_rec,(X[j]-X[i])*(Y[l]-Y[k]))

print(min_rec)