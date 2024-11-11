n,k=[int(x) for x in input().split()]
doma=[int(x) for x in input().split()]
doma.append(0)
counter=0
tot=0
prev=0
for item in doma:
    if item!=prev:
        counter+=1
    else:
        if counter>tot:
            tot=counter
        counter=1
    prev=item
print(tot)
