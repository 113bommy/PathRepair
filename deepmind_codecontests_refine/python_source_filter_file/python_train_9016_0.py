inp = lambda : map(int, input().split())
n, k, m = inp()
d = {}
for i in range(m):
    d[i] = []
for i in inp():
    d[i % m].append(str(i))
for i in d.values():
    if len(i) >= k:
        print("YES")
        print(" ".join(i[:k]))
        quit()
print("NO")
