def team(n, children):
    arr1, arr2, arr3 = [], [] ,[]
    for i in range(n):
        if children[i] == 1:
            arr1.append(i)
        elif children[i] == 2:
            arr2.append(i)
        else:
            arr3.append(i)
    # if not all((arr1,arr2,arr3)):
    #     print(0)
    print(min(len(arr1),len(arr2),len(arr3)))
    while all((arr1,arr2,arr3)):
        print(arr1.pop(0),arr2.pop(0),arr3.pop(0))
n = int(input())
children = list(map(int,input().split()))
team(n,children)




