input()
lst = []
for i in map(int, input().split(" ")):
    lst.append(i)
print(lst.count(1))
j = 0
coun = []
for j in range (len(lst)-1):
    if lst[j] > lst[j+1]:
        coun.append(lst[j])
coun.append(lst[-1])
for a in coun:
    print(a,end=" ")