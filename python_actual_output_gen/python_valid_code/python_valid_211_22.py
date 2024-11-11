n,l = map(int,input().split())
list1 = sorted(list(map(int,input().split())))
list2 = []
for m in range(0,n-1):
    k = list1[m+1] - list1[m]
    list2.append(k/2)
list2.append(list1[0])
list2.append(list1[-1])
print(max(list2))