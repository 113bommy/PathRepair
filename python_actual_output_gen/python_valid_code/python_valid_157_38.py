N,K = map(int,input().split())
N = list(map(int,input().split()))
N.sort()
print(sum(N[K-1:]))