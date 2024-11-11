k,n = map(int,input().split())	
a = list(map(int,input().split()))
D=[A[0]-A[-1]+K]
for i in range(N-1):
    D.append(A[i+1]-A[i])
print(K-max(D))