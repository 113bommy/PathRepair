for _ in range(int(input())):
    am = int(input())
    n = list(map(int,list(input())))
    odd1 = 0
    even1 = 0
    odd2 = 0
    even2 = 0
    for i in range(am):
        if (i+1)%2 == 1:
            if n[i]%2 == 1:
                odd1+=1
            else:
                even1+=1
        else:
            if n[i]%2 == 1:
                odd2+=1
            else:
                even2+=1
    if am%2 == 1:
        if odd1 >= even1:
            print(1)
        else:
            print(2)
    else:
        if even2 >= odd2:
            print(2)
        else:
            print(1)