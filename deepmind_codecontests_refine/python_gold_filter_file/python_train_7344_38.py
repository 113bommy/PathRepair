## Juicer

nandbandd =[int(i) for i in input().split()]
n = nandbandd[0]
b = nandbandd[1]
d = nandbandd[2]
aser=[int(i) for i in input().split()]
khalat=0
no_of_wastes=0
for i in range(n):
    if aser[i] > b:
        continue
    else:
        khalat += aser[i]
    if khalat >d:
        khalat=0
        no_of_wastes+=1
print(no_of_wastes)