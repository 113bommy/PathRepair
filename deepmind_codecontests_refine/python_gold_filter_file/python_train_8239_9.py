import math
n = int(input())
coal = input().split()
coals = []
for j in range(0,n):
    coals.append(int(coal[j]))
total = coals[0]
size = coals[0]
indices = [1]
for j in range(1,n):
    total = total+coals[j]
    if (coals[j]*2 <= coals[0]):
        size = size+coals[j]
        indices.append(j+1)
if (total%2 == 0):
    cap = int(total/2)+1
else:
    cap = int(total/2)+1
if (size >= cap):
    print (len(indices))
    s = ""
    for j in indices:
        s = s+str(j)+" "
    print (s)
else:
    print (0)

