import math
n,l = input("").split()
n,l = eval(n),eval(l)
List = list(map(int, input("").split())) 
d = []
if List.count(0) == 0:
    d.append(List[0])
List.sort()
if List.count(l) == 0:
    d.append(l - List[n-1])
for i in range(n):
    if i+1 < n:
        d.append((List[i+1] - List[i])/2)
print("{:.9f}".format(max(d)))