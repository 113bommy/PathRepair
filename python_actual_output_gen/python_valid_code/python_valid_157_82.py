N,K = map(int,input().split())
l = sorted(list(map(int,input().split())))
print(sum(l[:N-K-1:-1]))