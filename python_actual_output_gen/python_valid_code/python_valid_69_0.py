N, K = map(int,input().split())
A = [0]+list(map(int,input().split()))

p = 0
for i in range(K+1,N+1):
    print(["No","Yes"][p < A[i]])
    p = A[i-K+1]
