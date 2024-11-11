N, K = map(int, input().split())
H = map(int,input().split())
print(sum(sorted(H, reverse=True)[K::]))