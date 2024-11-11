h,w = map(int,input().split())
print(4 * (2 ** ((h - 1) * (w - 1))) % 998244353)