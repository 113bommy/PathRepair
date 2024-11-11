garbage = input()
l = list(map(int, input().rstrip().split(" ")))
t = set(l)
m = 0
for i in set(l):
    c = l.count(i)
    if c>m:
        m = c

print(c, len(t))