N=list(map(int, input().split()))
K=int(input())
print(sum(N)+max(N)*(2**K-1))