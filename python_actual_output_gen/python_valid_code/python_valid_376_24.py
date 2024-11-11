N = int(input())
A = list(map(int,input().split()))
A.sort()
print(sum(A[N//2:])*2-A[-1]-(N%2)*A[0])