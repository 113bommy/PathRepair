m,n = [int(i) for i in input().split()]
mas = set(range(1,n+1))

setd = []
sets = []
for i in range(m):
    s = set()
    [s.add(int(j)) for j in input().split()[1:]]
    setd.append(s)
    sets.append(mas.difference(s))


#print(setd)
#print(sets)


flag = True
for i in range(m):
    for j in range(m):
        if sets[i].issuperset(setd[j]):
            flag = False

            break

if flag:
    print("possible")
else:
    print("impossible")