n,k = map(int, input().split())


counter = 0
for i in range(n):
    a = set([int(j) for j in input()])
    ks = {j for j in range(k)}
    if ks.issubset(a):
        counter+=1

print(counter)