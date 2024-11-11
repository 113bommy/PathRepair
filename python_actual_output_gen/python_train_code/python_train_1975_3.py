n,m=map(int,input().split())
list1=[0]*n
for i in range(m):
    list2=[*map(int,input().split())]
    list1[list2.index(max(list2))]
print(list1.index(max(list1))+1)