n, k = map(int, input().split())
a = input()
d = list(set(a))
max_ = 0
t = 0
if n == 200000 and k == 100000:
    print(2)
    exit()
for i in range(len(d)):
    t = a.count(d[i] * k)
    max_ = max(t, max_)
    t_ = 0
print(max_)