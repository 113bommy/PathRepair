count = 0
z = set()
x = set()
p,q,l,r = list(map(int, input().split(' ')))
for i in range(p):
    a, b = list(map(int, input().split(' ')))
    [z.add(n) for n in range(a, b+1)]
for j in range(q):
    c,d = list(map(int, input().split(' ')))
    [x.add(n) for n in range(c, d+1)]

for k in range(r-l+1):
    for l in x:
        if l+k in z:
            count+=1
            break
print(count)
