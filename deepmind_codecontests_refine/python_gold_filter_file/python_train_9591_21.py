n , k = map(int, input().split())
l = list(map(int, input().split()))

ei = 0
si = 0
ecnt = [0]*k
scnt = [0]*k
c = []
for i in range(len(l)):
    if l[i] == 1:
        ei = ei + 1
        x = i%k
        ecnt[x] += 1
    else:
        si = si + 1
        x = i%k
        scnt[x] += 1
for i in range(k):
    c.append(ecnt[i]-scnt[i])

if ei > si:
    print(ei-si-min(c))
elif si > ei:
    print(si-ei+max(c))
else:
    print(max(max(c), abs(min(c))))


