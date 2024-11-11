n = int(input())
l = list(map(int, input().split()))
l = list(sorted(l, reverse=True))
p = []
d = []
for i in l:
    if i % 2 == 0:
        p.append(i)
    else:
        d.append(i)
if abs(len(p) - len(d)) <= 1 :
    print(0)
elif len(p) > len(d):
    print(sum(p[len(d)-1:]))
else:
    print(sum(d[len(p)-1:]))
