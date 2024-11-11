import sys
n = int(sys.stdin.readline())
instructions = []
max_const = 2000000000
min_const = -2000000000
for i in range(n):
    instructions.append(list(map(str,sys.stdin.readline().split())))
print(instructions,n)
criteria = []
for i in instructions:
    if (i[0] == ">" and i[2] == "Y") or (i[0] == "<=" and i[2] == "N"):
        criteria.append((int(i[1])+1,max_const))
    elif (i[0] == ">=" and i[2] == "Y") or (i[0] == "<" and i[2] == "N"):
        criteria.append((int(i[1]),max_const))
    elif (i[0] == "<" and i[2] == "Y") or (i[0] == ">=" and i[2] == "N"):
        criteria.append((min_const,int(i[1])-1))
    else:
        criteria.append((min_const,int(i[1])))
mini = min_const
maxi = max_const
for i in criteria:
    mini = max(mini,i[0])
    maxi = min(maxi,i[1])
if mini>maxi:
    print("Impossible")
else:
    print(mini)
