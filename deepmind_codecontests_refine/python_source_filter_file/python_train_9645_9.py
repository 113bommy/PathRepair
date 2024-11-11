
n = int(input())
result = 0

cset = map(int, input().split())
nset = []

cset = list(set(cset))

#print (cset)

for i in range(0,len(cset)):
    if cset[i]==0:
        continue

    else:
        nset.append(cset[i])

print (len(cset))