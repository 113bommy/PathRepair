n,k = map(int,input().split())
l = list(map(int,input().split()))
o = []
for i in range(n):
    if l[i] in o:
        continue

    o.append(l[i])
    if len(o) > k:
        o.pop(0)

    print(o)

print(len(o))
o = o[::-1]
print(*o)