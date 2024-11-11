s = input()
List = list(s)
a = []
i = 0
j = len(List)-1
val = len(List)

for i in range(len(List)):
    if List[i] == '(':
        for j in range(val-1,i,-1):
            if List[j] == ')':
                a.append(i)
                a.append(j)
                val = j
                break
    if i>=j or i==len(List)-1:
        break
if len(a) == 0:
    print(0)
else:
    print(1)
    print(len(a))
    a.sort()
    for l in a:
        print(l+1,end=" ")
