X = list(map(int, input().split()))
K = int(input())
print(sum(X) + max(X)*2**(K-1))