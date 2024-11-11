# 書けばわかる 裏になるのは奇数回訪れる場所
n, w = map(int, input().split())
print(n*w-(2*n+2*w-4))
