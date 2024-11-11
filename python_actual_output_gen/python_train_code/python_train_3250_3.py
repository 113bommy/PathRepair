n, k = map(int, input().split())

v = [len(input()) for i in range(n)]
ans = len(input())
mn = 1
mx = 0
for x in v:
    if x < ans:
        mn += 1
    if x <= ans:
        mx += 1
mn += 5*(mn//k)
mx += 5*(mx//k)
print(mn, mx)
