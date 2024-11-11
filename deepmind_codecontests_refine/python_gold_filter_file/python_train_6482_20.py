for k in range(int(input())):
    n=int(input())
    l=[int(p) for p in input().split()]
    z=-1
    for i in range(len(l)):
        if l[i]>1:
            z=i
            break

    if z!=-1:
        if z%2==0:
            print("First")
        else:
            print("Second")
    else:
        if n%2==0:
            print("Second")
        else:
            print("First")
