N, K = map(int, input().split())
Hs = map(int,input().split())
print(sum(sorted(Hs, reverse=True)[K::])