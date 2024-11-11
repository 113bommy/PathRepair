n=int(input())
if n%3!=2:
    list1=[1,1,n-2]
    print(list1[0],end=" ")
    print(list1[1],end=" ")
    print(list1[2],end=" ")
else:
    list1=[2,1,n-3]
    print(list1[0],end=" ")
    print(list1[1],end=" ")
    print(list1[2],end=" ")

