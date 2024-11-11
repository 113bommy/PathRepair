l = list(map(int,input().split()))
z = []
if len(set(l)) == len(l):
    print(sum(l))

else:
    for i in set(l):
        if l.count(i) > 1:
            z.append(i*l.count(i))
    print(sum(l)-max(z))