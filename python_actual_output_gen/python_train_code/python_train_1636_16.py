case=int(input())
for i in range(case):
    n=int(input())
    list1=[int(v) for v in input().split()]
    list1.sort()
    list2=[]
    for j in range(n-1):
        list2.append(abs(list1[j]-list1[j-1]))
    print(min(list2))