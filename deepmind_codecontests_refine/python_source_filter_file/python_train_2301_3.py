n, k = map(int, input().split())
a = list(map(int, input().split()))
d = max([a.count(q) for q in a])
f = len(set(a))
g = (d+k)//k
print(f*g*k-n)
