n = int(input())

S = [int(x) for x in input().split()][1:]
D = []
for i in S:
    if not (i in D):
        D.append(i)
for i in range(0,n-1):
    temp = []
    L = [int(x) for x in input().split()][1:]
    for i in D:
        if i in L:
            if not (i in temp):
                temp.append(i)
    D = temp

print(' '.join([str(x) for x in D]))