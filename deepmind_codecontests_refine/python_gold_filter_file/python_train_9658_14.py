inpl = lambda: list(map(int,input().split()))
N = int(input())
A = inpl()
print(sum(A[i]%2 for i in range(0,N,2)))
