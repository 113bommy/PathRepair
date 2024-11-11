from bisect import*
n, *l = map(int, open(0).read().split())
print(sum(max(0, bisect_left(l, l[i] + l[j]) - j - 1) for i in range(n) for j in range(i+1, n)))