N, K = input().split()
N = int(N)
K = int(K)
a = [int(input()) for i in range(N)]

a.sort()
print(a)

print(min([a[i+K-1]-a[i] for i in range(N-K+1)]))