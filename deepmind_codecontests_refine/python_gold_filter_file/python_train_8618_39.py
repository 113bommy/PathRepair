N,K = list(map(int, input().split()))
h = list(map(int, input().split()))

print(sum(x>=K for x in h))