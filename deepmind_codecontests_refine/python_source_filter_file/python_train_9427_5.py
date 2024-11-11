n, m = map(int,input().split())
l = sorted([len(input()) for i in range(n)])
p = len(input())
k = l.index(p)
b = k + 1
b += k//(m*5)
wk = n - l[::-1].index(p) -1
w = wk + 1
w += wk// (m*5)
print(b, w)