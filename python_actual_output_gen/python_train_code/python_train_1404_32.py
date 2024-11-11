mod = 998244353
w, h = map(int, input().split())
w += h
w = w%(mod-1)
print(2**w)
